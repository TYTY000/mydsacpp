#ifndef __LABY__
#define __LABY__

#include "./cell.h"

bool labyrinth ( Cell laby[LABY_MAX][LABY_MAX], Cell* c, Cell* dest ) 
{
  if ( ( c->status != AVAILABLE ) || ( dest->status != AVAILABLE ) ) return false;
  Stack< Cell* > path;
  c->incoming = UNKNOWN; c->status = ROUTE; path.push(c);
  do
  {
    displayLaby();
    Cell* p = path.peek();
    if ( p == dest ) return true;
    while ( ( c->outgoing = nextDirec( c->outgoing ) ) < XX ) // try 
    {
      if ( neighbor(c)->status == AVAILABLE ) break;
    }
    if ( c->outgoing >= XX ) // try done && NO WAY OUT
    {
      c->status = BACKTRACKED;
      c = path.pop();
    } else {                 // try done && NOT NO WAY
      path.push( c = go(c) );
      c->outgoing = UNKNOWN;
      c->status = ROUTE;
    }
  } while( !path.empty() );
  return false;
}


#endif // !__LABY__
