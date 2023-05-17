/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-15 21:09:12
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-15 21:17:58
 */

#include "stack_vec.h"
int testID = 0;

static size_t dice( size_t range ) { return rand() % range + 1; }
template <typename T>
void testStack ( Rank n )
{
   Stack<T> S;
   printf ( "\n  ==== Test %2d. Growing stack\n", testID++ );
   while ( S.size() < n ) {
      if ( S.empty() || ( 30 < ( rand() % 100 ) ) ) {
         T e = (T) dice ( 2 * n );
         printf ( "pushing " ); std::cout << e << " ...\n" ;
         S.push ( e );
      } else {
         printf ( "popping with ... " ); std::cout << S.pop() << " ...\n" ; 
      }
      std::cout << S << std::endl; 
   }
   printf ( "\n  ==== Test %2d. Shrinking stack\n", testID++ );
   while ( !S.empty() ) {
      if ( 70 < dice ( 100 ) ) {
         T e = (T) dice ( 2 * n );
         printf ( "pushing " ); std::cout << e << " ...\n" ; 
         S.push ( e );
      } else {
         printf ( "popping with ... " ); std::cout << S.pop() << " ...\n" ;
      }
      std::cout << S << std::endl; 
   }
   printf ( "\n  ==== Test successful!\n" );
}

int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   srand((unsigned int)time(NULL));
   // srand( 31415926 );
   testStack<int> ( atoi ( argv[1] ) );
   return 0;
}
