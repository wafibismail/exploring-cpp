#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

/*
 * Function: init
 * --------------
 * Includes all initializations and related one-time parameter settings
 */

void init (void)
{
    // Only assign color, not put window on screen
    glClearColor (0.5, 0.5, 1.0, 0.0); // Set display-window color to blue.

    glMatrixMode (GL_PROJECTION); // Set projection parameters.
    gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

/*
 * Function: lineSegment
 * ---------------------
 * This is the geometric description of the "picture" to be displayed,
 * which is to be referenced by glutDisplayFunc later on
 *
 * This is refered to as the display callback function, which is to be
 * invoked whenever the display window might need to redisplayed
 * E.g. when the window is moved
 */

void lineSegment (void)
{
    // GL_COLOR_BUFFER_BIT symbolic constant being specified here
    //   signifies it's the bit values in the color buffer (refresh buffer)
    //   that is set to the colors specified in glClearColor
    glClear (GL_COLOR_BUFFER_BIT); // Clear display window.

    // Set the object (i.e. line segment) color to dark green via f RGB values
    glColor3f (0.0, 0.2, 0.0);


    glBegin (GL_LINES);
    glVertex2i (180, 15); // Specify line-segment geometry.
    glVertex2i (10, 145);
    glEnd ( );

    glFlush ( ); // Process all OpenGL routines as quickly as possible.
}
/*
 * Function: main
 * --------------
 * Set up the display window and get the line segment onto the screen
 */
int main (int argc, char** argv)
{
    // Initialize GLUT with glutInit
    //can also process any command-line argument (not needed for now)
    glutInit (&argc, argv);

    // Specify non-default values:
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // Set display mode.
    glutInitWindowPosition (50, 100); // Set top-left display-window position.
    glutInitWindowSize (400, 300); // Set display-window width and height.

    // Create display window with specified caption
    glutCreateWindow ("An Example OpenGL Program");

    init ( ); // Execute initialization procedure.

    // Specify what the display window is to contain
    //   I.e. pass the picture definition to glutDisplayFunc
    //   In this case it's an OpenGL code for describing a line segment
    glutDisplayFunc (lineSegment);

    // After the statement below is executed, all created display windows
    //   with their graphic content are activated
    glutMainLoop ( ); // Display everything, enter infinite loop, check for inputs
}
