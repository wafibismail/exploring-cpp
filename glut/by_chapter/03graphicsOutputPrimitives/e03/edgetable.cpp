#include "edgetable.hpp"

#include <iostream>
#include <sstream>

EdgeTable::EdgeTable(VertTable *vertTable)
{
    this->vertTable = vertTable;

    size = 20;
    currNdx = 0;
    edges = new Edge[size];
}

EdgeTable::~EdgeTable() { delete[] edges; }

Edge *EdgeTable::add(GLfloat ux, GLfloat uy, GLfloat uz,
          GLfloat vx, GLfloat vy, GLfloat vz)
{
    Vert *v0 = vertTable->add(ux, uy, uz);
    Vert *v1 = vertTable->add(vx, vy, vz);
    return add(v0, v1);
}

Edge *EdgeTable::add(Vert *v0, Vert *v1)
{
    Edge *ePtr = getPtr(v0, v1);
    if (ePtr == NULL) {
        if (currNdx == size) return edges;

        ePtr = &edges[currNdx++];

        ePtr->v0 = v0;
        ePtr->v1 = v1;

        std::stringstream labelSS;
        labelSS << "E" << currNdx;

        ePtr->label = labelSS.str();
    }
    return ePtr;
}

void EdgeTable::coutAll()
{
    std::cout<<"EDGES:"<<std::endl;
    for (int i = 0; i < currNdx; i++) {
        Edge e = edges[i];
        std::cout<<e.label<<":("<<e.v0->label<<","<<e.v1->label<<")"<<std::endl;
    }
    std::cout<<std::endl;
}

Edge *EdgeTable::getPtr(Vert *v0, Vert *v1)
{
    for (int i = 0; i < currNdx; i++) {
        Edge e = edges[i];
        if (e.v0 == v0 && e.v1 == v1) return &edges[i];
    }
    return NULL;
}
