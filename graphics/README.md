Current location:
- Page 41 - Error handling

Personal note
- I removed these environment paths to avoid clashes:
  - C:\Strawberry\c\bin
  - C:\Strawberry\c\perl\site\bin
  - C:\Strawberry\c\perl\bin
- And added C:\msys64\mingw64\bin

OpenGL naming conventions, examples:
- functions: glBegin, glClear, glCopyPixels, glPolygonMode
- symbolic constants: GL_2D, GL_RGB, GL_POLYGON, GL_AMBIENT_AND_DIFFUSE
- specific data types names: GLbyte, GLshort, GLfloat, GLdouble, GLboolean
  - Because the size e.g. of an integer specification, can be different across different machines

Relevant libraries:
- OpenGL basic (core) library
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