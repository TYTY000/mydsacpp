#ifndef __CELL__ 
#define __CELL__

#include "../stack.h"

typedef enum { UNKNOWN, XX, EAST, SOUTH, WEST, NORTH } Direc;
typedef enum { AVAILABLE, ROUTE, BACKTRACKED, WALL } Status;

inline Direc nextDirec ( Direc direc ) { return Direc ( direc + rand() % 4 ); }
struct Cell
{
  int x, y;
  Status status;
  Direc incoming, outgoing;
};

#define LABY_MAX 24
Cell laby[LABY_MAX][LABY_MAX];

inline Cell* neighbor ( Cell* cell )
{
  switch ( cell->outgoing ) {
    case EAST : return cell + LABY_MAX;
                break;
    case SOUTH: return cell + 1;
                break;
    case WEST : return cell - LABY_MAX;
                break;
    case NORTH: return cell - 1;
                break;
    default:    exit(-1);
  }
}

inline Cell* go ( Cell* cell )
{
  Cell* next;
  switch ( cell->outgoing ) {
    case EAST : next = cell + LABY_MAX; next->incoming = WEST ; break;
    case SOUTH: next = cell + 1;        next->incoming = NORTH; break;
    case WEST : next = cell - LABY_MAX; next->incoming = EAST ; break;
    case NORTH: next = cell - 1;        next->incoming = SOUTH; break;
    default:  exit(-1);
  }
  return next;
}

#endif // !__CELL__
