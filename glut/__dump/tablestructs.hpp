#ifndef TABLESTRUCTS_HPP_INCLUDED
#define TABLESTRUCTS_HPP_INCLUDED

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <string>

struct Vert { GLfloat x, y, z; std::string label; };

struct Edge { Vert *v0, *v1; std::string label; };

struct Face { Edge **edges; int nEdges; std::string label; };

#endif // TABLESTRUCTS_HPP_INCLUDED
