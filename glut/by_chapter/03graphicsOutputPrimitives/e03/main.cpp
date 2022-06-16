/*
 * Instruction:
 * ------------
 * Set up a procedure for establishing the geomet-
 * ric data tables for any input set of points defining
 * the polygon facets for the surface of a three-
 * dimensional object.
 */

#include "facetable.hpp"

int main(int argc, char** argv) {
    VertTable *vp = new VertTable();
    Vert *v1 = vp->add(0,0,0);
    Vert *v2 = vp->add(1,0,0);

    EdgeTable *ep = new EdgeTable(vp);
    Edge *e1 = ep->add(v1, v2);
    Edge *e2 = ep->add(v2, vp->add(1,0,1));
    Edge *e3 = ep->add(vp->add(1,0,1), vp->add(0,0,0));

    FaceTable *fp = new FaceTable(ep);
    int f1Size = 3;
    Edge **f1Edges = new Edge*[f1Size];
    f1Edges[0] = e1;
    f1Edges[1] = e2;
    f1Edges[2] = e3;
    fp->add(f1Edges,f1Size);


    vp->coutAll();
    ep->coutAll();
    fp->coutAll();

    delete[] f1Edges;
    delete fp;
    delete ep;
    delete vp;
    return 0;
}
