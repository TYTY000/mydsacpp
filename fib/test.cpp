#include "./fib.h"
#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
  Fib fib(20);

  cout << fib.get() << '\t' ;
  fib.prev();
  cout << fib.get() << '\t' ;
  return 0;
}
