# About
This repo contains the relevant (for me) C++ related learning materials. <br>
The notes here are for my own use, so may be unusable for other readers.

### Sections

#### preliminary:
[Programming Abstractions with C++](https://web.stanford.edu/dept/cs_edu/resources/textbook/) (by [Eric S. Roberts](https://cs.stanford.edu/people/eroberts/)) is the book which this section is based upon. 

Stopped at page 546 (562) i.e. Section 12.7 - Copying objects<br>

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
- Rational class interface & implementation codes on chapter 6.3, pg 288-291
- Chapters 7 until 10
  - programming concepts not specific to C++
    - recursion
    - recursive strategies
    - backtracking algorithms
    - algorithmic analysis
- Try out stack-heap diagram drawing, Chapter 12.5, page 538 (554)

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
- author's approach to designing classes:
  - 1) Think generally about how clients are likely to use the class
    - Design it around their convenience (not the implementer's)
  - 2) Determine (intuitively, generally) what information belongs in the private state of each object
  - 3) Define a set of constructors
    - and perhaps consider whether the constructors need to apply any restriction to ensure resulting objects' validity
  - 4) Enumerate the operations that will become the public method
    - i.e. specify and write the prototypes
    - rememember the principles of unity, simplicity, sufficiency, generality, and stability
  - 5) Code and test the implementation
    - Once the interface is done, write the code that implements it
    - Revisit the interface design if needed to ensure features perform to acceptable levels of efficiency
- When using a class as a client (as opposed to as an implementor), it would make sense to ignore the private section of a class, even though C++ requires that the private section be included in the interface
- tokens: logical units of a string that may be larger than a single character
- sometimes i.e. when some amount of internal state needs to be maintained, it may be appropriate to encapsulate the entire program inside a class (e.g. demo in [CheckoutLineClass.cpp](https://github.com/wafibismail/exploring-cpp/preliminary/CheckoutLineClass.cpp))
  - in which case, the main program creates a variable of that class and invokes a method in that class to get the program running
- C++ defines the data type char to be exactly one byte in size (ASCII)
  - use the type wchar_t (wide characters) for programs that work with expanded charcter sets
- in C++, the size of an object is the sum of the sizes of the instance variables it contains
  - note though that compilers are allowed to add memory space to the underlying representations of an object as doing so sometimes allows for a more efficeint machine language code.
    - e.g. the size of a Point object (with two int instance variables) must be at least eight bits, though it might be larger
- sizeof:
  - sizeof(int) returns the number of bytes required to store a value of type int
  - sizeof x returns the number of bytes required to store the variable x
- array
  - in most cases, array size declarations should be specified as symbolic constants e.g.
    - const int N_ELEMENTS = 10; // and use this in square brackets in the array's declaration
  - selection: the process of identifying a particular element in an array
  - number of elements = sizeof ARR / sizeof ARR[0];
    - use this for statically declared arrays only
    - for dynamic arrays, better to set size of array as the approximate maximum number of elements (allocated size) i.e. larger than needed - then use only part of it
      - with this method, a separate int variable keeping track of the number of values that are in use (effective size)
- freeing memory
  - delete ip;
  - delete[] array;
  - *if it's a linked list, delete recursively*
- on choosing an implementation strategy w/ regard to efficiency
  - *"One way to ensure that there are no hidden costs is to limit the implementation so that it relies only on the most primitive operations supported by the language"*
    - example demonstrating this in CharStack implementation
      - primitive array used as opposed to some abstract class e.g. Vector
- if stuck in debugging as far as memory allocation is concerned, consider drawing heap-stack diagrams
  - refer to page 538 (554)
- unit testing: strategy of checking each class or interface separately in isolation from any other module
  - can use &lt;cassert> library
    - assert(*test*)
      - as long as the test expression evaluates to true, the assert macro has no effect
      - else an error message is generated
  - refer to [CharStackUnitTest.cpp](https://github.com/wafibismail/exploring-cpp/preliminary/CharStackUnitTest.cpp))