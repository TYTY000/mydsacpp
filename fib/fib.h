#ifndef __FIBONACCI__
#define __FIBONACCI__

using Rank = unsigned int;

class Fib {
private:
  Rank a, b;  
public:
  Fib ( Rank n ){
    a = 1; b = 1; while ( a < n ) next();
  }
  Rank get() { return a; }
  Rank next() { a += b; b = a - b; return a; }
  Rank prev() { b = a-b; a = a-b; return a; }
};

#endif // !__FIBONACCI__
