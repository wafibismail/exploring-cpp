### Bookmark

#### preliminary:
Stopped at page 146 (162) i.e. the strlib.h library<br>

Skipped:
- Exercises page 50(66) to 54(70)
  - points already clear, (but still good general programming exercises)
- Exercises chapter 2
- Graphics related exercise on chapter 2

!!!!!:
- reference parameters e.g. "& a" (in Quadratic.cpp)
- first use of cerr in Quadratic.cpp, made to a library w/ interface (error.cpp & error.h respectively)
- interfaces (a.k.a abstraction boundary) should be
  - unified - if some function doesn't fit the interface theme, put it elsewhere. also, ensure consistency e.g. use degrees only or radians only
  - simple - hide complexity (e.g. in implementation) from client, even in the commentary; contain only what client needs to know
  - sufficient - must provide sufficient functionality to meet clients' needs
  - general - flexible as to be usable by many different clients; inclusion of functionality should not be based on percieved importance
  - stable - no breaking changes