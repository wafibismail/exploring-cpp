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

#include <iostream>

struct Vert { GLint x, y, z; };
struct Edge { int v0, v1; };
struct Face { Edge edges[]; };

class VertexTable {
private:
    Vert *vertices;
    int size, currCount;

    void expand () {
        Vert *oldVerts = vertices;
        size *= 2;
        vertices = new Vert[size];

        for (int k = 0; k < currCount; k++) {
            Vert currVert;

            currVert.x = oldVerts[k].x;
            currVert.y = oldVerts[k].y;
            currVert.z = oldVerts[k].z;

            vertices[k] = currVert;
        }

        delete[] oldVerts;
    }

public:
    VertexTable () {
        size = 2;
        vertices = new Vert[size];
        currCount = 0;
    }

    int add (Vert newVert) {
        int matchedIndex = getIndex(newVert);
        if (matchedIndex == -1) {
            if (currCount == size)
                expand ();

            vertices[currCount] = newVert;
            matchedIndex = currCount++;
        }
        return matchedIndex;
    }
    int add (GLint x, GLint y, GLint z) {
        Vert newVert;
        newVert.x = x;
        newVert.y = y;
        newVert.z = z;

        return add(newVert);
    }

    int getIndex(Vert vert) {
        for (int k = 0; k < currCount; k++) {
            if (
                vert.x == vertices[k].x &&
                vert.y == vertices[k].y &&
                vert.z == vertices[k].z
            ) return k;
        }
        return -1;
    }

    Vert getVert(int index) { return vertices[index]; }
    void printVert(int index) {
        std::cout<<"{"
            <<getVert(index).x<<", "
            <<getVert(index).y<<", "
            <<getVert(index).z<<"}";
    }
};

int main(int argc, char** argv) {
    VertexTable *testVT = new VertexTable();
    Vert *vt = testVT->add(4, 3, 5);
    testVT->printVert(0);
    delete testVT;
    return 0;
}
