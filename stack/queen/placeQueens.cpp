#include "./queen_stack.h"
extern int Solutions;
void placeQueens ( const Rank& N )
{
  Stack<Queen> S;
  Queen q ( 0, 0 );
  do
  {
    if ( N <= S.size() || N <= q.y )
    {
      q = S.pop(); q.y++;
    } else {
      while ( ( q.y < N ) && ( S.find ( q ) != nullptr ) ){
        q.y++; nCheck++;
      }
      if ( N > q.y ) {
        S.push ( q );
        if ( N <= S.size() ) Solutions++;
        q.x++; q.y = 0;
      }
    } if ( Step == runMode ) displayProgress( S, N );
  } while( q.x > 0 || q.y < N );
}
