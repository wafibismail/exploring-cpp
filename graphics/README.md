Current location:
- Page 92 - circle midpoint routine

Need to revisit:
- From book
  - plane equations

Personal note
- I removed these environment paths to avoid clashes:
  - C:\Strawberry\c\bin
  - C:\Strawberry\c\perl\site\bin
  - C:\Strawberry\c\perl\bin
- And added C:\msys64\mingw64\bin

Software standard systems:
- GKS - Graphical Kernel System
  - from 1984 by ISO & ANSI
- PHIGS - Programmer's Hierarchical Interactive Graphics System
  - extension of GKS
  - increased capabilities for:
    - heirarchical object modeling,
    - color specifications,
    - surface rendering, and
    - picture manipulations
- PHIGS+
  - extension of PHIGS
  - provide 3D surface-rendering capabilities not available in PHIGS
- GL - Graphics Library
  - designed for real-time rendering,
  - initially a set of routines that come with graphics workstations from SGI
  - and extended to other hardware systems
  - eventually became a de facto standard
- OpenGL - a hardware independent version of GL
  - maintained by the OpenGL Architecture Review Board

Standard planning/relevant organizations:
- ISO - International STandards Organization
- ANSI - American National Standards Institutes
- SGI - Silicon Graphics, Inc.
- OpenGL Architecture Review Board
  - a consortium of representatives from many graphics companies and organizations

Functions available in graphics programming packages:
- graphics output primitives
- attributes
- geometric and modeling transformations
- viewing transformations
- input functions
- picture-structuring operations
- control operations

OpenGL naming conventions, examples:
- functions: glBegin, glClear, glCopyPixels, glPolygonMode
- symbolic constants: GL_2D, GL_RGB, GL_POLYGON, GL_AMBIENT_AND_DIFFUSE
- specific data types names: GLbyte, GLshort, GLfloat, GLdouble, GLboolean
  - Because the size e.g. of an integer specification, can be different across different machines

Relevant libraries:
- OpenGL basic (core) library - device independent
- OpenGL Utility (GLU)
  - provides routines for
    - setting up viewing and projection matrices,
    - describing complex objects with line and polygon approximation,
    - displaing quadrics and B-splines,
    - using linear approximations,
    - processing the surface-rendering operations
    - other complex tasks
  - Every OpenGL implementation includes the GLU library,
  - functions start with the prefix *glu*
- Open Inventor
  - provides routines and predefined object shapes for
    - interactive three-dimensional applications
  - written in C++
- window-system libraries that support OpenGL functions
  - OpenGL Extension to the X window System (GLX)
    - provided set of routines prefixed with glX
  - Apple GL (AGL)
    - for window-management operations in Apple systems
    - prefixed with agl
  - Windows-to-OpenGL (WGL) interface
    - prefixed with wgl
  - Presentation Manager to OpenGL (PGL)
    - interface for the IBM OS/2
    - uses the prefix pgl for library routines
  - OpenGL Utility Toolkit (GLUT)
    - provides a library of functions for interacting with any screen-windowing system
    - also contains methods for describing and rendering quadric curves and surfaces
    - prefixed with glut
    - http://www.opengl.org/resources/libraries/glut/
    - https://sourceforge.net/projects/codeblocks/files/Binaries/17.12/Windows/codeblocks-17.12mingw-setup.exe/download
    - freeglut 3.0.0 MinGW Package
      - https://www.transmissionzero.co.uk/files/software/development/GLUT/freeglut-MinGW.zip
      - copy freeglut/bin/freeglut.dll to C:/Windows
      - copy freeglut/include/GL/* to CodeBlocks/MinGW/include/GL
      - copy freeglut/lib/* (non recursive files only) to CodeBlocks/MinGW/lib
      - CodeBlocks/share/CodeBlocks/templates/glut.cbp
        - replace glut32 to freeglut
      - CodeBlocks\share\CodeBlocks\templates\wizard\glut\wizard.script
        - replace glut32 to freeglut
      - done. if prompted on glut's directory. its in CodeBlocks/MinGW

Errors
- can occur in a call to a base library routine or a GLU routine
- OpenGL only records one error at a time, meaning
  - once an error occur, no other error code will be recorded
    - until our program explicitly queries the OpenGL error state
- generally should be checked for at least once in our display callback rountines
  - and more frequently if we are using OpenGL features we have never used before

```cpp
// Get the current error state
// This returns the symbolic constant
//   GL_NO_ERROR if everything is fine
GLenum code;
code = glGetError();
```

```
OpenGL (different from GLU) error codes:

Symbolic constant     Meaning
GL_INVALID_ENUM       A GLenum argument was out of range
GL_INVALID_VALUE      A numeric argument was out of range
GL_INVALID_OPERATION  An operation was illegal in the current OpenGL state
GL_STACK_OVERFLOW     The command would cause a stack overflow
GL_STACK_UNDERFLOW    The command would cause a stack underflow
GL_OUT_OF_MEMORY      There was not enough memory to execute a command
```

```cpp
// General error-reporting function
#include <stdio.h>

GLenum errorCheck()
{
    GLenum code;
    const GLubyte *string; // const keep this' value from being changed

    code = glGetError();
    if (code != GL_NO_ERROR)
    {
        string = gluErrorString(code); // points to string in the GLU library
        fprintf(stderr, "OpenGL error: %s\n", string);
    }

    return code;
}
```

To do: Draw a rough specification of an app or a few apps with these characteristics; <br>
Use visual diagrams and/or text, listing the properties of the objects in this app. <br>
It's important to use this specification as it will used to modify the app later on
```
Checklist:
[/] The objects are complex in shape or texture.
[/] The objects can be approximated fairly well by simpler shapes.
[/] Some of the objects are comprised of fairly complex curved surfaces.
[?] The objects lend themselves to being represented two-dimensionally at
    first, even if unrealistically.
[/] The objects can be represented as a hierarchically organized group of
    smaller objects/parts.
[/] The objects change position and orientation dynamically in response
    to user input.
[/] The lightning conditions change in the application, and the object
    appearances change under these varying conditions.
```

```
App 1: generic mine
- gui: live text display
  - amount of money, gems
- blacksmith
  - anvil
    - inverted pyramid top
    - flat cuboid base
  - hammer
    - T shape
      - cuboid head
      - cuboid body
    - rotate when hitting
- cave environment
  - lighning from defferent sources
    - open entrance
    - fire torches on walls
  - textured rock walls
  - capsuled shaped
    - spherical ends
    - cyllindrical center
    - flat bottom/floor
- various types of rocks
  - group of either
    - cones, pyramids, cyllinders, cuboids or fractals
  - different colors
  - when hit
    - decay visibly
    - emit appropriately/similarly shaped children
- graphic: pickaxe
  - T shape
    - curved head
    - cyllinder body
  - rotate when hitting
```