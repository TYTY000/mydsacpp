#include "./stack.h"
#include <iomanip>
#include <boost/core/demangle.hpp>
#include <boost/type_index.hpp>
  static char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                       'A', 'B', 'C', 'D', 'E', 'F' };

void convert ( Stack<char>& S, int64_t n, int base)
{
  int remain = 0;
  while ( n > 0 )
  {
    remain = n % base;
    S.push( digit[remain] );
    n /= base;
  }
}

int main (int argc, char *argv[])
{
  //if ( 3 > argc ) { printf ( "Usage: %s <convert number>\a\a\t<base>\n", argv[0] ); return 1; }
  Stack<char> S;
  int64_t n = 12345678987654321;
  int base = 16;
  std::cout << n << '\t' << std::hex << n << std::endl;
  convert( S, n, base );
  std::cout << S << std::endl;
  return 0;
} 
