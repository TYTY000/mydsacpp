#include "queen_stack.h"

#define QUEEN_MAX 20

RunMode runMode;
int Solutions = 0;
int nCheck = 0;

int main ( int argc, char* argv[] ) {
   for ( int i = 1; i < argc - 1; i++ )
      if ( !strcmp ( "-step", argv[i] ) ) runMode = Step;
   Rank nQueen = atoi ( argv[argc-1] ); 
   if ( QUEEN_MAX < nQueen || 1 > nQueen ) { 
     fprintf ( stderr, "\nUsage: %s [-step] <nQueen(%d)>\n", argv[0], QUEEN_MAX );
      return -1;
   }
   placeQueens ( nQueen ); 
   cout  << Solutions << " solution(s) found after "
         << nCheck << " check(s) for " 
         << nQueen << " queen(s)\n";
   return 0;
}
