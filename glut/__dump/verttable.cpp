#include "verttable.hpp"

#include <iostream>
#include <sstream>

VertTable::VertTable()
{
    size = 20;
    currNdx = 0;
    verts = new Vert[size];
}
VertTable::~VertTable() { delete[] verts; }

Vert *VertTable::add(GLfloat x, GLfloat y, GLfloat z)
{
    Vert *vPtr = getPtr(x, y, z);
    if (vPtr == NULL) {
        if (currNdx == size) return verts;

        vPtr = &verts[currNdx++];

        vPtr->x = x;
        vPtr->y = y;
        vPtr->z = z;

        std::stringstream labelSS;
        labelSS << "V" << currNdx;

        vPtr->label = labelSS.str();
    }
    return vPtr;
}

void VertTable::coutAll()
{
    std::cout<<"VERTICES:"<<std::endl;
    for (int i = 0; i < currNdx; i++) {
        Vert v = verts[i];
        std::cout<<v.label<<":("<<v.x<<","<<v.y<<","<<v.z<<")"<<std::endl;
    }
    std::cout<<std::endl;
}

Vert *VertTable::getPtr(GLfloat x, GLfloat y, GLfloat z)
{
    for (int i = 0; i < currNdx; i++) {
        Vert v = verts[i];
        if (v.x == x && v.y == y && v.z == z) return &verts[i];
    }
    return NULL;
}
