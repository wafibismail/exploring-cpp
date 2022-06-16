#ifndef FACETABLE_HPP_INCLUDED
#define FACETABLE_HPP_INCLUDED

#include "edgetable.hpp"

class FaceTable
{
public:
    FaceTable(EdgeTable *edgeTable);
    ~FaceTable();

    Face *add(Edge **edges, int nEdges);
    void coutAll();

private:
    EdgeTable *edgeTable;
    Face *faces;
    int size;
    int currNdx;

    Face *getPtr(Edge **edges, int nEdges);
};

#endif // FACETABLE_HPP_INCLUDED
