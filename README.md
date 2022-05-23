### Bookmark

#### preliminary:
Stopped at page 261 (277) i.e. designing classes <br>

Skipped sections (and some notes) worth re-exploring:
- Exercises in each chapter
- Graphics related demos on chapter 2
- Vector class demos on chapter 5.1
  - ways of declaring vectors:
    - Vector<type> vec;
    - Vector<type> vec(size);
    - Vector<type> vec = { x1, x2, x3 };
    - Vector< Vector<type> > vec(size, Vector<type>(size));
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
- parameterized classes a.k.a. templates: classes that include a base-type specification. E.g. Vector e.g. Vector<char>, Vector<int>, etc.
- bounds-checking: testing whether an index is valid
- on declaration of primitive variables (without explicit initialization), the memory used to hold the variables still holds the value it has before the declaration
- on declaration of classes, the case is different due to constructors being invoked, which leads to initializations.
- associative arrays: arrays implemented using maps as their underlying representation
- range-based for loops can be used in conjunction with Vector, Grid, Map, Set, Lexicon but NOT Stack nor Queue (as unrestricted access to these structures would violate the "*only one element visible at one time*" principle)
- several advantages of Abstract Data Types over primitive types:
  - simplicity
  - flexibility
  - security