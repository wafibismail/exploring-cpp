#ifndef TABLESTRUCTS_HPP_INCLUDED
#define TABLESTRUCTS_HPP_INCLUDED

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

struct Vert { GLfloat x, y, z; };

struct Edge { Vert *v1, *v2; };

struct Face { Edge *edges; };

#endif // TABLESTRUCTS_HPP_INCLUDED
