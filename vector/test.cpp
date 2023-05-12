#include "./vector.h"
#include <iostream>

#define dice(X) ( rand() % (X) )
template <typename T> void TestFind( Vector<T>& V ) {
   for ( Rank i = 0; i < V.size(); i++ ) { //ÒÀ´Î²éÕÒÏòÁ¿ÖÐÔªËØ£¬µ±È»³É¹¦
      T e =  V[i]; std::cout << e;
      Rank r = V.find ( e );
      if ( -1 != r ) printf ( " : found at V[%d] = %d", r, V[r] );
      else printf ( " : not found until V[%d] <> %d", r, e );
      printf ( "\n" );
   }
   for ( Rank i = 0; i <= V.size(); i++ ) { //ÒÀ´Î²éÕÒÃ¿¶ÔÏàÁÚÔªËØµÄ¾ùÖµ£¬¿ÉÄÜ³É¹¦
      T a = ( 0 < i ) ? V[i - 1] : V[0] - 4;
      T b = ( i < V.size() ) ? V[i] : V[V.size()-1] + 4;
      T e =  ( a + b ) / 2; std::cout << e << '\t';
      Rank r = V.find ( e );
      if ( -1 != r ) printf ( " : found at V[%d] = %d", r, V[r] );
      else printf ( " : not found until V[%d] <> %d", r, e );
      printf ( "\n" );
   }
}

template <typename T> void TestSearch( Vector<T>& V ) {
   for ( Rank i = 0; i < V.size(); i++ ) { //ÒÀ´Î²éÕÒÏòÁ¿ÖÐÔªËØ£¬µ±È»³É¹¦
      T e =  V[i]; std::cout << e ; printf(": by ");
      Rank r = V.search ( e );
      if ( V[r] == e ) printf ( "found at V[%d] = %d", r, V[r] );
      else printf ( "found at V[%d] = %d <> %d\a\a", r, V[r], e );
      printf ( "\n" );
   }
   for ( Rank i = 0; i <= V.size(); i++ ) { //ÒÀ´ÎÏàÁÚÔªËØµÄ¾ùÖµ£¬¿ÉÄÜ³É¹¦
      T a = ( 0 < i ) ? V[i - 1] : V[0] - 4;
      T b = ( i < V.size() ) ? V[i] : V[V.size()-1] + 4;
      T e =  ( a + b ) / 2; std::cout << e ; printf(": by ");
      Rank r = V.search ( e );
      printf ( "V[%3d] =", r ); ( -1 == r ) ? std::cout << "-INF" << '\t' : std::cout << V[r] << '\t'; printf ( "  ~  " );
      printf ( "V[%3d] =", r + 1 ); ( r + 1 < V.size() ) ? std::cout << V[r + 1] << '\t' : std::cout << "+INF" << '\t';
      bool ordered = true;
      if ( ( -1 != r  ) && ( V[r] > e ) ) ordered = false;
      if ( ( r + 1 < V.size() ) && ( V[r + 1] <= e ) ) ordered = false;
      if ( !ordered ) printf ( "\tincorrect search\a\a" );
      printf ( "\n" );
   }
}

template <typename T> //ÔªËØÀàÐÍ
void TestOrderedInsertion( Vector<T>& V, Rank n ) {
   while ( n * 2 > V.size() ) {
      T e = dice ( ( T ) n * 2 );
      printf ( "Inserting " ); std::cout << e ; printf ( " by " );
      V.insert ( V.search ( e ) + 1, e );
    std::cout << V ;
   }
}

template <typename T>
struct Increase
{
  Increase(unsigned int n) : num(n) {} 
  virtual void operator()(T& e) { e += num;} 
  private:
  unsigned int num;
};

template <typename T>
void increase( Vector<T>& V )
{
  Increase<T> inc2(2);
  V.traverse(inc2);
}

int testID = 0; //²âÊÔ±àºÅ
#define PRINT(X) ( std::cout << X )
template <typename T> //ÔªËØÀàÐÍ
void testVector( int testSize ) {
   printf ( "\n  ==== Test %2d. Generate a random vector\n", testID++ );
   Vector<T> V;
   for ( int i = 0; i < testSize; i++ ) V.insert ( dice ( i + 1 ), dice ( ( T ) testSize * 3 ) ); //ÔÚ[0, 3n)ÖÐÑ¡Ôñn¸öÊý£¬Ëæ»ú²åÈëÏòÁ¿
   PRINT ( V );
   V.unsort();
   PRINT ( V );
   printf ( "\n  ==== Test %2d. Lowpass on\n", testID++ ); PRINT ( V );
   int i = V.size(); while ( 0 < --i ) { V[i-1] *= 7; V[i-1] += V[i]; V[i-1] >>= 3; }    PRINT ( V );
   printf ( "\n  ==== Test %2d. Increase\n", testID++ ); PRINT ( V );
   increase ( V ); PRINT ( V );
   printf ( "\n  ==== Test %2d. FIND in\n", testID++ ); PRINT ( V );
   TestFind<T> ( V );
   printf ( "\n  ==== Test %2d. Sort degenerate intervals each of size 1 in\n", testID++ ); PRINT ( V );
   for ( Rank i = 0; i < V.size(); i += V.size() / 5 ) { V.sort ( i, i+1 ); PRINT ( V ); } //element by element
   Rank trunk = int(ceil(V.size()/5.0));
   printf ( "\n  ==== Test %2d. Sort %d intervals each of size <=%d in\n", testID++, V.size()/trunk, trunk ); PRINT ( V );
   for ( Rank i = 0; i < V.size(); i += trunk ) { printf("[%d , %d)\n", i, std::min ( V.size(), i + trunk ) ); V.sort ( i, std::min ( V.size(), i + trunk ) ); PRINT ( V ); } //interval by interval
   printf ( "\n  ==== Test %2d. Sort the entire vector of\n", testID++ ); PRINT ( V );
   V.sort();   PRINT ( V );
   printf ( "\n  ==== Test %2d. FIND in\n", testID++ ); PRINT ( V );
   TestFind<T> ( V );
   printf ( "\n  ==== Test %2d. SEARCH in\n", testID++ ); PRINT ( V );
   TestSearch<T> ( V );
   printf ( "\n  ==== Test %2d. Unsort interval [%d, %d) in\n", testID++, V.size() / 4, 3 * V.size() / 4 ); PRINT ( V );
   V.unsort ( V.size() / 4, 3 * V.size() / 4 );   PRINT ( V );
   printf ( "\n  ==== Test %2d. Unsort interval [%d, %d) in\n", testID++, 0, V.size() ); PRINT ( V );
   V.unsort();   PRINT ( V );
   printf ( "\n  ==== Test %2d. Copy interval [%d, %d) from\n", testID++, V.size() / 4, 3 * V.size() / 4 ); PRINT ( V );
   Vector<T> U ( V, V.size() / 4, 3 * V.size() / 4 );
   PRINT ( U );
   printf ( "\n  ==== Test %2d. Copy from\n", testID++ ); PRINT ( V );
   Vector<T> W ( V );
   PRINT ( W );
   printf ( "\n  ==== Test %2d. Clone from\n", testID++ ); PRINT ( U );
   W = U;
   PRINT ( W );
   printf ( "\n  ==== Test %2d. Remove redundancy in unsorted\n", testID++ ); PRINT ( V );
   printf ( "%d node(s) removed\n", V.deduplicate() );   PRINT ( V );
   printf ( "\n  ==== Test %2d. Sort the entire vector of\n", testID++ ); PRINT ( V );
   V.sort();   PRINT ( V );
   printf ( "\n  ==== Test %2d. Remove redundancy in sorted\n", testID++ ); PRINT ( V );
   printf ( "%d node(s) removed\n", V.uniquify() );   PRINT ( V );
   printf ( "\n  ==== Test %2d. FIND in\n", testID++ ); PRINT ( V );
   TestFind<T> ( V );
   printf ( "\n  ==== Test %2d. SEARCH & INSERT in\n", testID++ ); PRINT ( V );
   TestOrderedInsertion<T> ( V, testSize );  PRINT ( V );
   printf ( "\n  ==== Test %2d. Remove redundancy in sorted\n", testID++ ); PRINT ( V );
   printf ( "%d node(s) removed\n", V.uniquify() );   PRINT ( V );
}


int main( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   srand((unsigned int)time(NULL)); //Ëæ»úÖÖ×Ó
   //srand( 31415926 ); //¹Ì¶¨ÖÖ×Ó£¨¼ÙÖÖ×Ó£¬µ÷ÊÔÓÃ£©
   testVector<int> ( atoi ( argv[1] ) ); //ÔªËØÀàÐÍ¿ÉÒÔÔÚÕâÀïÈÎÒâÑ¡Ôñ
   return 0;
}
