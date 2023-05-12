#ifndef __SIMU__
#define __SIMU__

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <climits>

#include "./queue.h"
#include "./customer.h"
#include "./bestWindow.h"
#include "./displayProgress.h"

int bestWindow ( Queue< Customer > windows[], Rank nWin );
void printCustomer ( Customer c );
void displayProgress ( Queue< Customer > windows[], Rank nWin, Rank now );
void simulate ( Rank, Rank );

extern int delay;

void simulate ( Rank nWin, Rank time )
{
  Queue< Customer >* windows = new Queue< Customer >[nWin];
  for (Rank now = 0; now < time; now++) {
    if ( rand() % ( nWin + 1 ) )
    {
      Customer c; c.time = rand() % 98 + 1;
      c.window = bestWindow ( windows, nWin );
      windows[c.window].enqueue( c );
    }
    for (Rank i = 0; i < nWin; i++) {
      if ( !windows[i].empty() ) {
        if ( -- windows[i].peek().time <= 0 )
          windows[i].dequeue();
        displayProgress ( windows, nWin, now );
        delay > 0 ?
          usleep (delay) :
          getchar();
      }
    }
  }
  delete[] windows;
}
#endif // !__SIMU__
