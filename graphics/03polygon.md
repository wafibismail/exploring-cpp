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