#include "facetable.hpp"

#include <iostream>
#include <sstream>

FaceTable::FaceTable(EdgeTable *edgeTable)
{
    this->edgeTable = edgeTable;

    size = 20;
    currNdx = 0;
    faces = new Face[size];
}

FaceTable::~FaceTable() { delete[] faces; }

Face *FaceTable::add(Edge **edges, int nEdges)
{
    Face *fPtr = &faces[currNdx++];

    fPtr->edges = edges;
    fPtr->nEdges = nEdges;

    std::stringstream labelSS;
    labelSS << "F" << currNdx;

    fPtr->label = labelSS.str();

    return fPtr;
}

void FaceTable::coutAll()
{
    std::cout<<"SURFACES:"<<std::endl;
    for (int i = 0; i < currNdx; i++) {
        Face f = faces[i];
        std::cout<<f.label<<":(";
        for (int j = 0; j < f.nEdges; j++) {
            std::cout<<f.edges[j]->label;
            if (j < f.nEdges -1) std::cout << ",";
        }
        std::cout<<")"<<std::endl;
    }
    std::cout<<std::endl;
}

Face *FaceTable::getPtr(Edge **edges, int nEdges)
{
    for (int i = 0; i < currNdx; i++) {
        if (faces[i].nEdges == nEdges) {
            for (int j = 0; j < nEdges; j++) {
                if (faces[i].edges[j] != edges[j]) break;
                if (j == nEdges - 1) return &faces[i];
            }
        }
    }
    return NULL;
}
