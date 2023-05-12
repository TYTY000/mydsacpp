#include "./PQvector.h"
#include <iostream>

#define DSA_PQ_COMPLHEAP 1
#define dice(x) ( rand() % x )
#define print(x) ( std::cout << x )
template <typename PQ, typename T> void testHeap( Rank n ) {
   Rank s = 2*n/3; T* A = new T[s]; //´´½¨ÈÝÁ¿Îª2*n/3µÄÊý×é£¬ÇÒ
   for ( T i = 0; i < 2 * (T)n / 3; i++ ) A[i] = dice( ( T ) 3 * n ); //ËùÓÐ´ÊÌõËæ»ú
   /*DSA*/printf ( "%d random keys created:\n", s );
   /*DSA*/for ( Rank i = 0; i < s; i++ ) print( A[i] ); printf ( "\n" );
   PQ heap( A + n / 6, n / 3 ); //ÅúÁ¿½¨¶Ñ£¨PQ_ComplHeapÊµÏÖÁËRobert FloydËã·¨£©
   delete [] A;
   /*DSA*/print( heap );
   while ( heap.size() < n ) { //Ëæ»ú²âÊÔ
      if ( dice( 100 ) < 70 ) { //70%¸ÅÂÊ²åÈëÐÂ´ÊÌõ
         T e = dice( ( T ) 3 * n ); /*DSA*/printf ( "Inserting " ); print( e ); printf( " ...\n" );
         heap.insert( e ); /*DSA*/printf ( "Insertion done\n" );
      } else { //30%¸ÅÂÊÕª³ý×î´ó´ÊÌõ
         if ( !heap.empty() ) {
            /*DSA*/printf( "Deleting max ...\n" );
            T e = heap.delMax();/*DSA*/printf( "Deletion done with" ); print( e ); printf( "\n" );
         }
      }
      /*DSA*/print( heap );
   }
   while ( !heap.empty() ) { //Çå¿Õ
      T e = heap.delMax();/*DSA*/printf ( "Deletion done with" ); print ( e ); printf( "\n" );
      /*DSA*/print( heap );
   }
}

/******************************************************************************************
 * ÓÅÏÈ¼¶¶ÓÁÐ²âÊÔ
 ******************************************************************************************/
int main( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   srand((unsigned int)time(NULL)); //Ëæ»úÖÖ×Ó
   //srand( 31415926 ); //¹Ì¶¨ÖÖ×Ó£¨¼ÙÖÖ×Ó£¬µ÷ÊÔÓÃ£©
#if defined(DSA_PQ_LEFTHEAP)
   testHeap<PQ_LeftHeap<int>, int>( atoi ( argv[1] ) ); //´ÊÌõÀàÐÍ¿ÉÒÔÔÚÕâÀïÈÎÒâÑ¡Ôñ
#elif defined(DSA_PQ_COMPLHEAP)
   testHeap<PQVector<int>, int>( atoi ( argv[1] ) ); //´ÊÌõÀàÐÍ¿ÉÒÔÔÚÕâÀïÈÎÒâÑ¡Ôñ
#elif defined(DSA_PQ_LIST)
   testHeap<PQ_List<int>, int>( atoi ( argv[1] ) ); //´ÊÌõÀàÐÍ¿ÉÒÔÔÚÕâÀïÈÎÒâÑ¡Ôñ
#else
   printf( "PQ type not defined yet\n" );
#endif
   return 0;
}
