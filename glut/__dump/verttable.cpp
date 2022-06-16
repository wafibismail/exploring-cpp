#include "verttable.hpp"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
/* Constructor and Destructor */

VertTable::VertTable()
{
    size = 2;
    vertices = new Vert[size];

    currPos = 0;
}

VertTable::~VertTable()
{
    delete[] vertices;
}

/* Public methods */

int VertTable::addVert(Vert vert)
{
    if (currPos == size) expandCapacity();
    vertices[currPos] = vert;

    return currPos++;
}

int VertTable::addCoords(GLfloat x, GLfloat y, GLfloat z)
{
    Vert v; v.x = x; v.y = y; v.z = z;
    return addVert(v);
}

int VertTable::getVertIndex(Vert v)
{
    for (int i = 0; i < currPos; i++) {
        if (
            vertices[i].x == v.x &&
            vertices[i].y == v.y &&
            vertices[i].z == v.z
        ) return i;
    }
    return -1;
}

Vert VertTable::getVert(int ndx)
{
    return vertices[ndx];
}

int VertTable::getActiveSize()
{
    return currPos;
}
/* Private methods implementation */

void VertTable::expandCapacity()
{
    Vert *oldVerts = vertices;
    vertices = new Vert[size*=2];
    for (int i = 0; i < currPos; i++) {
        vertices[i] = oldVerts[i];
    }
    delete[] oldVerts;
}
