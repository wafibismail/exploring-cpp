/*
 * Instruction:
 * ------------
 * Set up a procedure for establishing the geomet-
 * ric data tables for any input set of points defining
 * the polygon facets for the surface of a three-
 * dimensional object.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "verttable.hpp"
#include <iostream>

int main(int argc, char** argv) {
    VertTable *vt = new VertTable;
    Vert v; v.x = 1, v.y = 2, v.z = 3;
    int oh;
    oh = vt->addVert(v);
    vt->addCoords(2.0, 2.0, 2.0);
    vt->addCoords(2.2, 2.2, 2.2);
    std::cout<<vt->getVert(oh).y;
    delete vt;
    return 0;
}
