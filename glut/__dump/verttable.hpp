#ifndef VERTTABLE_HPP_INCLUDED
#define VERTTABLE_HPP_INCLUDED

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "tablestructs.hpp"

class VertTable {
public:
    VertTable(); // constructor
    ~VertTable(); // destructor
    int addVert(Vert vert); // return index
    int addCoords(GLfloat x, GLfloat y, GLfloat z); // return index
    int getVertIndex(Vert vert); // return existing index, or -1
    Vert getVert(int index);
    int getActiveSize();
private:
    Vert *vertices;
    int size, currPos;

    void expandCapacity();
};

#endif // VERTTABLE_HPP_INCLUDED
