#ifndef __DISP_LABY__
#define __DISP_LABY__

void printLabyCell ( Cell* elem ) {
   printf ( "%d -> (%d, %d) -> %d\n",
            ( ( Cell* ) elem )->incoming,
            ( ( Cell* ) elem )->x,
            ( ( Cell* ) elem )->y,
            ( ( Cell* ) elem )->outgoing );
}

#include <string>
void displayLaby() { //©¼©¸©´©°©¦©¤
   static std::string pattern[5][5] = {
      "©à", "©à", "©à", "©à", "©à",
      "©à", "  ", "©°", "©¤", "©¸",
      "©à", "©°", "  ", "©´", "©¦",
      "©à", "©¤", "©´", "  ", "©¼",
      "©à", "©¸", "©¦", "©¼", "  "
   };
   system ( "clear" );
   printf ( "  " );
   for ( int j = 0; j < labySize; j++ )
      ( j < 10 ) ? printf ( "%2X", j ) : printf ( " %c", 'A' - 10 + j );
   printf ( "\n" );
   for ( int j = 0; j < labySize; j++ ) {
      ( j < 10 ) ? printf ( "%2X", j ) : printf ( " %c", 'A' - 10 + j );
      for ( int i = 0; i < labySize; i++ )
         if ( goalCell == &laby[i][j] )
            printf ( "©" );
         else
            switch ( laby[i][j].status ) {
               case WALL:  printf ( "¨" );   break;
               case BACKTRACKED: printf ( "¡ð" );   break;
               case AVAILABLE: printf ( "  " );   break;
               default   : printf ( "%s", pattern[laby[i][j].outgoing][laby[i][j].incoming] );   break;
            }
      printf ( "\n" );
   }//for
}//displayLaby


#endif // !__DISP_LABY__
