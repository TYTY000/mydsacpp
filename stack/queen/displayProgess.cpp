#include "./queen_stack.h"
#include <iomanip>
using namespace std;
Rank N = 0;
extern int Solutions;

void displayRow ( Queen& q )
{
  std::cout << setw(2) << q.x;
  Rank i = 0;
  while ( i++ < q.y ) std::cout << "[ ]";
  std::cout << "[¨]";
  while ( i++ < N ) std::cout << "[ ]";
  std::cout << setw(2) << q.y << std::endl;
}

void displayProgress ( Stack<Queen>& S, Rank nQueen )
{
  system ( "clear" );
  N = nQueen; S.traverse ( displayRow );
   if ( nQueen <= S.size() ) {
      cout  << Solutions << " solution(s) found after " << nCheck << " check(s)\a";
      getchar();
   }
}
