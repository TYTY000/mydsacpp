#ifndef __RAND_LABY__
#define __RAND_LABY__

#include <cstdio>

void randLaby() { //Éú³ÉËæ»úµÄÃÔ¹¬
   labySize = LABY_MAX / 2 + rand() % ( LABY_MAX / 2 ); /*DSA*/printf ( "Using a laby of size %d ...\n", labySize ); getchar();
   for ( int i = 0; i < labySize; i++ )
      for ( int j = 0; j < labySize; j++ ) {
         laby[i][j].x = i;
         laby[i][j].y = j;
         laby[i][j].incoming   =
            laby[i][j].outgoing   =   UNKNOWN;
         laby[i][j].status = WALL; //±ß½ç¸ñµã±ØÐëÊÇÇ½
      }
   for ( int i = 1; i < labySize - 1; i++ )
      for ( int j = 1; j < labySize - 1; j++ )
         if ( rand() % 4 ) laby[i][j].status = AVAILABLE; //75%µÄ¸ñµãÎª¿Õ¿ÉÓÃ
   startCell = &laby[rand() % ( labySize-2 ) + 1][rand() % ( labySize-2 ) + 1];
   goalCell  = &laby[rand() % ( labySize-2 ) + 1][rand() % ( labySize-2 ) + 1];
   startCell->status = goalCell->status = AVAILABLE; //ÆðÊ¼¸ñµã±ØÐë¿ÉÓÃ
}

#endif // !__RAND_LABY__
