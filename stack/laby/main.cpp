#include "../stack.h"
#include "./cell.h"

int labySize;
Cell* startCell;
Cell* goalCell;
#include "./displayLaby.h"
#include "./laby.h"
#include "./randLaby.h"
#include "./readLaby.h"

int main ( int argc, char* argv[] ) {
   srand ( ( unsigned int ) time ( NULL ) ); //ÉèÖÃËæ»úÖÖ×Ó
   ( 1 < argc ) ? readLaby ( argv[1] ) : randLaby(); //Ê¹ÓÃÖ¸¶¨ÃÔ¹¬ÎÄ¼þ£¬»òËæ»úÉú³É
   labyrinth ( laby, startCell, goalCell ) ? //Æô¶¯Ëã·¨
   printf ( "\nRoute found\a\n" ) :
   printf ( "\nNo route found\a\n" );
   getchar();
   return 0;
}
