#include<iostream>
using namespace std;
#include "./QuadList.cpp"
#include "SkipList.cpp"
#include "../print/skiplist.h"

#define dice(X) (rand()%(X))

template <typename K, typename V> //key¡¢value
void testSkiplist ( Rank n ) {
   Skiplist<K, V> L;
   while ( L.size() < n )
      switch ( dice ( 3 ) ) {
         case 0: { //²éÕÒ£¬³É¹¦ÂÊ <= 33.3%
            K key = dice ( ( K ) n * 3 ); //[0, 3n)·¶Î§ÄÚµÄkey
            printf ( "Searching for " ); print ( key ); printf ( " ... " );
            V* pValue = L.get ( key );
            if(pValue){ printf ( "found with " ), print ( *pValue );}else printf ( "Not found" ); printf ( "\n\n" );
            break;
         }
         case 1: { //É¾³ý£¬³É¹¦ÂÊ <= 33.3%
            K key = dice ( ( K ) n * 3 ); //[0, 3n)·¶Î§ÄÚµÄkey
            printf ( "Removing " ); print ( key ); printf ( " ... " );
            if ( L.remove ( key ) ) { printf ( "Done\n" ); print(L); }
            else printf ( "Entry not exists\n\n" );
            break;
         }
         default: {//²åÈë£¬³É¹¦ÂÊ == 100%
            K k = dice ( ( K ) n * 3 ); V v = ( V ) 'A' + dice ( 26 ); //ÔÚ[0, 2n)*['A'~'Z']·¶Î§ÄÚµÄ´ÊÌõ
            printf ( "Inserting <" ); print ( k ); printf ( "," ); print ( v ); printf ( "> ... " );
            L.put ( k, v ); printf ( "Done\n" );
            print ( L );
            break;
         }
      }
   while ( L.size() > 0 ) {
      K key = dice ( ( K ) n * 3 ); //[0, 3n)·¶Î§ÄÚµÄkey
      printf ( "Removing " ); print ( key ); printf ( " ... " );
      L.remove ( key ) ? printf ( "Done\n" ) : printf ( "Entry not exists\n" );
      print ( L ); printf("\n");
   }
}

/******************************************************************************************
 * Ö÷³ÌÐò
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   srand((unsigned int)time(NULL)); //Ëæ»úÖÖ×Ó
   //srand( 31415926 ); //¹Ì¶¨ÖÖ×Ó£¨¼ÙÖÖ×Ó£¬µ÷ÊÔÓÃ£©
   testSkiplist<int, char> ( atoi ( argv[1] ) ); //ÔªËØÀàÐÍ¿ÉÒÔÔÚÕâÀïÈÎÒâÑ¡Ôñ
   return 0;
}
