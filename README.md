# About
This repo contains the relevant (for me) C++ related learning materials. <br>
The notes here are for my own use, so may be unusable for other readers.

### Sections

#### preliminary:
[Programming Abstractions with C++](https://web.stanford.edu/dept/cs_edu/resources/textbook/) (by [Eric S. Roberts](https://cs.stanford.edu/people/eroberts/)) is the book which this section is based upon. 

Stopped at page 279 (295) i.e. adding operators to the Direction type <br>

Skipped sections (and some notes) worth re-exploring:
- Exercises in each chapter
- Graphics related demos on chapter 2
- Vector class demos on chapter 5.1
  - ways of declaring vectors:
    - Vector&lt;type> vec;
    - Vector&lt;type> vec(size);
    - Vector&lt;type> vec = { x1, x2, x3 };
    - Vector&lt; Vector&lt;type> > vec(size, Vector&lt;type>(size));
      - notice the required space separating the inner & outer angle brackets
- Stack class demos on chapter 5.2
  - including RPN Calculator
- Particular step in queue demo (CheckoutLine.cpp)
  - applying Queue class provided from the more convenient nonstandard library
- Map, Set & Lexicon classes demos on chapter 5.4 & 5.5

!!!!! (some notes, concepts and terms):
- reference parameters e.g. "& a" (in Quadratic.cpp)
- first use of cerr in Quadratic.cpp, made to a library w/ interface (error.cpp & error.h respectively)
- interfaces (a.k.a abstraction boundary) should be
  - unified - if some function doesn't fit the interface theme, put it elsewhere. also, ensure consistency e.g. use degrees only or radians only
  - simple - hide complexity (e.g. in implementation) from client, even in the commentary; contain only what client needs to know
  - sufficient - must provide sufficient functionality to meet clients' needs
  - general - flexible as to be usable by many different clients; inclusion of functionality should not be based on percieved importance
  - stable - no breaking changes
- parameterized classes a.k.a. templates: classes that include a base-type specification. E.g. Vector e.g. Vector&lt;char>, Vector&lt;int>, etc.
- bounds-checking: testing whether an index is valid
- on declaration of primitive variables (without explicit initialization), the memory used to hold the variables still holds the value it has before the declaration
- on declaration of classes, the case is different due to constructors being invoked, which leads to initializations.
- associative arrays: arrays implemented using maps as their underlying representation
- range-based for loops can be used in conjunction with Vector, Grid, Map, Set, Lexicon but NOT Stack nor Queue (as unrestricted access to these structures would violate the "*only one element visible at one time*" principle)
- several advantages of Abstract Data Types over primitive types:
  - simplicity
  - flexibility
  - security
- two ways of overloading binary operators in C++ for a newly defined class:
  - method within the class
    - left operand is the receiver object
    - right operand is passed as a parameter
      - bool operator==(Point pt);
  - free function outside the class
    - both operands are passed as parameters
      - bool operator==(Point pt1, Point pt2);
  - special note:
    - access to private instance variables can be made legal for a particular function by declaring the function as a *friend*
      - friend bool operator==(Point pt1, Point pt2);
    - ...which is applicable to classes as well
      - friend class *name*;