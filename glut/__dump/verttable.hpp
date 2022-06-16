#ifndef VERTTABLE_HPP_INCLUDED
#define VERTTABLE_HPP_INCLUDED

#include "tablestructs.hpp"

class VertTable {
public:
    VertTable();
    ~VertTable();

    Vert *add(GLfloat x, GLfloat y, GLfloat z);
    void coutAll();

private:
    Vert *verts;
    int size;
    int currNdx;

    Vert *getPtr(GLfloat x, GLfloat y, GLfloat z);
};

#endif // VERTTABLE_HPP_INCLUDED
