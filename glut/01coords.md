Covered:
- points
- lines
- curves


Specifying a 2D world-coordinate reference frame in OpenGL
  - Since the gluOrtho2D specifies an orthogonal projection,
  - we also need to be sure that the coordinate values are placed in the OpenGL projection matrix

Simplified, for the initial 2D examples, the coodinate frame for the screen display window can be defined <br>
with the following statements

```cpp
glMatrixMode(GL_PROJECTION)
glLoadIdentity();
gluOrtho2D(xmin, xmax, ymin, ymax);

/*
 * The display window will then be referenced
 *   by coordinates (xmin, ymin) at the lower left corner and
 *   by coordinates (xmax, yman) at the upper right corner.
 */
```

State the coordinate values for a single point with this OpenGL function

```cpp
glVertex* ();

/*
 * Where the * indicates that SUFFIX CODES are required for this function
 * 
 * SUFFIX CODES:
 * - are used to identify:
 *   - the spatial dimension,
 *   - the numerical data type to be used for the coordinate values,
 *     - e.g. i, s, f, d for integer, short, float & double respectively
 *   - a possible vector form for the coordinate specification
 * 
 * For point plotting, the argument of the glBegin function is the symbolic constant GL_Points
 * The glBegin/glEnd pair here encloses a list of glVertex functions
 */

glBegin(GL_POINTS);
  glVertex* ();
glEnd();

/*
 * Though the term "vertex" strictly refers to:
 * - a "corner" point of a polygon,
 * - the point of intersection of the sides of an angle,
 * - a point of intersection of an ellipse with its major axis, or
 * - other coordinate positions on geometric structures,
 * the glVertex function is used in OpenGL to specify coordinates for any point position,
 * i.e. used for:
 * - point, line and polygon specifications
 * - ... and most often, polygon patches are used to describe the objects in a scene
 * 
 * Arguments e.g. glVertex*(x,y,0), glVertex*(x,y,0,1):
 * - x coordinate
 * - y coordinate
 * - z coordinate (0 for 2D)
 * - scaling factor (it it's a homogeneous-coordinate representation)
 * 
 * These coordinate values can be listed explicitly in the glVertex function
 * 
 * Or a single argument can be used that references a coordinate position as an array
 * ... in which case v (for vector) needs to be appended as a third suffix code
 */
```

Three equally spaced points plotted along a two-dimensional, straight-line path with a slope of 2 (coords in integer pairs)

```cpp
glBegin(GL_POINTS);
  glVertex2i(50, 100);
  glVertex2i(75, 150);
  glVertex2i(100, 200);
glEnd();

// Or, alternatively

int point1[] = [50, 100];
int point2[] = [75, 150];
int point3[] = [100, 200];

glBegin(GL_POINTS);
  glVertex2iv(point1);
  glVertex2iv(point2);
  glVertex2iv(point3);
glEnd();
```

Two point positions in a three-dimensional world reference frame (floating-point values as coords):

```cpp
glBegin(GL_POINTS);
  glVertex3f(-78.05, 909.72, 14.60);
  glVertex3f(261.91, -5200.67, 188.33);
glEnd();
```

Another alternative, defining a C++ struct or class for specifying positions in various dimensions:

```cpp
// class definition
class wcPt2D {
public:
    GLfloat x, y;
}

// in program code - specifying a two-dimensional, world-coordinate point position
wcPt2D pointPos;

pointPos.x = 120.75;
pointPos.y = 45.30;

glBegin(GL_POINTS);
  glVertex2f(pointPos.x, pointPos.y);
glEnd();
```

Note: we can also use the OpenGL point-plotting functions within a C++ procedure to implement
the setPixel command. <br>
<br>

For line segments, to the glBegin function can be passed:
- GL_LINES
  - results in generally unconnected lines, unless some coordinate points are repeated (the lines share a vertex)
- GL_LINE_STRIP
  - results in a polyline, i.e. a sequence of connected lines from the first endpoint in the list to the last
- GL_LINE_LOOP
  - results in a closed polyline, same as GL_LINE_STRIP, except for the extra line connecting the first and last endpoints

## OpenGL Curve functions

OpenGL core library:
- does not include routines (as primitive functions) for generating basic curves e.g.:
  - **circles and ellipses**
- includes functions for displaying Bezier splines i.e.
  - polynomials that are defined with a discrete point set.

OpenGL Utility (GLU) library has routines for :
- three-dimensional quadrics e.g.:
  - spheres and cyllinders
- producing rational B-splines
  - i.e. a general class of splines that include the simpler Bezier curves.
  - which we can use to display **circles, ellipses**, and other 2D quadrics

OpenGL Utility Toolkit (GLUT) has routines for:
- some three-dimensional quadrics e.g.:
  - spheres, cones, and some other shapes

Alternative method:
- use polylines to approximate a simple curve
  - we need to only
    - locate a set of points along the curve path
    - and connect the points with straight-line segments
  - the more line secions we include, the smoother appearance of the curve

Another alternative method:
- write own curve-generation function (covered in later chapters)