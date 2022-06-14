Convex polygon: a polygon where:
- all its interior angles are less than or equal to 180%, or
- its interior lies completely on one side of the infinite extension line of any of its edges
- also, if any two points are selected in the interior of the polygon, the line segment joining the two points is also in the interior

Concave polygon: a polygon that is not convex
- .

Degenerate polygon
- describes a set of vertices that are
  - collinear,
    - generating a line segment
  - or have repeated coordinate positions
    - generating a polygon shape with
      - extraneous lines,
      - overlapping edges,
      - edges that have a length equal to 0
- a term which also applies to a vertex list that contains fewer than three coordinate positions

A graphics package could either:
- reject degenerate or nonplanax vertex sets
  - which requires extra processing to identify
- leave such considerations to the programmer

For concave polygons:
- Implementations of fill algorithms and other graphics routines are also more complicated
  - so it is more efficient to split them into a set of convex polygons before processing
    - concave polygon splitting algorithms is often not included in graphics libraries
    - Some graphics libraries including OpenGL even require all fill polygons to be convex
      - And some even only accept triangle fill areas, greatly simplifying many of the display algorithms

# IDENTIFYING CONCAVE POLYGONS

A concave polygon:
- it has the characteristics:
  - having at least one interior angle that is greater than 180 degrees
  - the extension of some of its edges will intersect other edges
  - some pair of interior points will produce a line segment that intersects the polygon boundary
- so any of these characteristics can be used as the basis for constructing an identification algorithm

E.g. 1:
- If we set up a vector for each polygon edge:
  - we can use the cross-product of adjacent edges to test for concavity
    - if convex, all such vector product will be of the same sign (+ve or -ve)

```
(E1_ X E2_)Z_ > 0
(E2_ X E3_)Z_ > 0
(E3_ X E4_)Z_ < 0
(E4_ X E5_)Z_ > 0
(E5_ X E6_)Z_ > 0
(E6_ X E1_)Z_ > 0
```

E.g. 2:
- Look at the polygon vertex positions relative to the extension line of any edge.
  - A polygon is concave if
    - some vertices are on one side of the extension line
    - and some vertices are on the other side

# SPLITTING CONCAVE POLYGONS

Once a polygon is identified to be concave, it can be split into a set of convex polygons, using
- edge vectors and edge cross-products, or
- vertex positions relative to an edge extension line to determine which vertices are on one side of this line and which are on the other

## Vector method
Given two consecutive vertex positions Vk and V(k+1) <br>
We define the edge vectors as <br>
<br>

Ek = V(k+1) - Vk <br>
<br>

Calculate the cross products of successive edge vectors in order around the polygon perimeter
- if some cross-products are positive
- while the others are negative
<br>

then the polygon is concave. Otherwise it is convex. <br>
<br>

This assumes that no series of successive vertices are collinear, in which case the cross-product for the two edge vertices would be zero. <br>
<br>

If all vertices are collinear, we have a degenerate polygon (a straight line) <br>
<br>

We can apply the vector method by processing edge vectors in a counter clockwise order <br>
<br>

If any cross-product is negative, the polygon is concave and we can split it along the first edge vector in the cross-product pair

```
E.g.
E1 = (1,0,0)   E2 = (1,1,0)
E3 = (1,-1,0)  E4 = (0,2,0)
E5 = (-3,0,0)  E6 = (0,-2,0)

Cross products between successive pairs Ej and Ek = Ejx*Eky - Ekx*Ejy
(as all are in the xy plane)

E1 x E2 = (0,0,1)    E2 x E3 = (0,0,-2)   <- has a negative z component, so we split
E3 x E4 = (0,0,2)    E4 x E5 = (0,0,6)       the polygon along the line of vector E2
E5 x E6 = (0,0,6)    E6 x E1 = (0,0,2)       (slope of 1, y-intercept of -1)
                                                            |
                                                            |
                We then determine the intersection of this--+
                line with the other polygon edges to split
                the polygon in two pieces

                No other edge cross-products are negative
                so the two new polygons are both convex
```

# Inside outside tests

Two commonly used algorithms:
- odd-even rule, a.k.a. odd-parity rule, or even-odd rule
  - from any arbitrary point, count the number of lines passed by it on the way out
    - odd count = interior, even count = exterior
- nonzero winding-number rule
  - from a line from any arbitrary point, count the number of intersections
    - counter-clockwise intersection = +1, clockwise intersection = -1
    - or, differentiate the direction with the z sign of cross product between:
      - the arbitrary line
      - the vector of the boundary passed
  - non-zero count = interior, zero count = exterior

# Polygon tables

```
 VERTEX TABLE     EDGE TABLE    SURFACE-FACET TABLE
V1: x1, y1, z1    E1: V1, V1    S1: E1, E2, E3
V2: x2, y2, z2    E2: V2, V3    S2: E3, E4, E5, E6
V3: x3, y3, z3    E3: V3, V1
V4: x4, y4, z4    E4: V3, V4
V5: x5, y5, z5    E5: V4, V5
                  E6: V5, V1

More data could be added to these tables
E.g. expand the edge table to include forward pointers into the surface-facet table
     so that a common edge between polygons could be identified more easily,
     which is particularly useful for rendering procedures that must vary
     surface shading smoothly across the edges from one polygon to the next
```