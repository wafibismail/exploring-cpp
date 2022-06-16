Abstract view of source codes

```cpp
// Structs
struct Vert { GLfloat x, y, z; string label; };
struct Edge { Vert *v0, *v1; string label; };
struct Face { Edge **edges; int nEdges; string label; };

// VertTable i.e. Vertex Table class
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

// EdgeTable i.e. Edge Table class
class EdgeTable {
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

// FaceTable class
class FaceTable {
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
```