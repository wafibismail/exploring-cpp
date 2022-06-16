#ifndef EDGETABLE_HPP_INCLUDED
#define EDGETABLE_HPP_INCLUDED

#include "verttable.hpp"

class EdgeTable
{
public:
    EdgeTable(VertTable *vertTable);
    ~EdgeTable();

    Edge *add(GLfloat ux, GLfloat uy, GLfloat uz,
              GLfloat vx, GLfloat vy, GLfloat vz);
    Edge *add(Vert *v0, Vert *v1);
    void coutAll();

private:
    VertTable *vertTable;
    Edge *edges;
    int size;
    int currNdx;

    Edge *getPtr(Vert *v0, Vert *v1);
};

#endif // EDGETABLE_HPP_INCLUDED
