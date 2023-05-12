#include <iostream>
using namespace std;

#include "./binTree.h"
#define dice(x) ( rand() % (x) ) 

int testID = 0; //²âÊÔ±àºÅ
int posi = 0;

// Ëæ»úÉú³ÉÆÚÍû¸ß¶ÈÎªhµÄ¶þ²æÊ÷
template <typename T> bool randomBinTree ( BinTree<T> & bt, BinNodePosi<T> x, int h ) {
   if ( 0 >= h ) return false; //ÖÁ¶àh²ã
   if ( 0 < dice ( h ) ) //ÒÔ1/hµÄ¸ÅÂÊÖÕÖ¹µ±Ç°·ÖÖ§µÄÉú³¤
      randomBinTree ( bt, bt.insert ( x, posi++ ), h - 1 );
   if ( 0 < dice ( h ) ) //ÒÔ1/hµÄ¸ÅÂÊÖÕÖ¹µ±Ç°·ÖÖ§µÄÉú³¤
      randomBinTree ( bt, bt.insert ( posi++, x ), h - 1 );
   return true;
}

// ÔÚ¶þ²æÊ÷ÖÐËæ»úÈ·¶¨Ò»¸ö½ÚµãÎ»ÖÃ
template <typename T> BinNodePosi<T> randomPosiInBinTree ( BinNodePosi<T> root ) {
   if ( !HasChild ( root ) ) return root;
   if ( !HasLChild ( root ) )
      return dice ( 6 ) ? randomPosiInBinTree ( root->rc ) : root;
   if ( !HasRChild ( root ) )
      return dice ( 6 ) ? randomPosiInBinTree ( root->lc ) : root;
   return dice ( 2 ) ?
          randomPosiInBinTree ( root->lc ) :
          randomPosiInBinTree ( root->rc ) ;
}

template <typename T> struct Double{
  virtual void operator () ( T& e ) { e *= 2; }
};

template <typename T> struct Increase{
  virtual void operator () ( T& e ) { e++; }
};

template <typename T> struct Hailstone{
  virtual void operator () ( T& e )
  {
    int step = 0;
    while ( e != 1 ) {
      ( e % 2 ) ? e = 3 * e + 1 : e /= 2;
      ++step;
    }
    e = step;
  }
};

  int c = 0;
void test3(){}
template <typename T> void   testBinTree ( int h ) { //²âÊÔ¶þ²æÊ÷
   printf ( "\n  ==== Test %2d. Generate a binTree of height <= %d \n", testID++, h );
   BinTree<T> bt; 
   bt.insert ( posi++ ) ; 
   randomBinTree<T> ( bt, bt.root(), h ); 
   cout << bt;
   printf ( "\n  ==== Test %2d. Double and increase all nodes by traversal\n", testID++ );
   Double<T> twice;  Increase<T> inc;
   std::cout << "pre traversal" << std::endl;
   bt.travPre ( twice ); cout << bt;
   bt.travPre ( inc );  cout << bt;
   std::cout << "mid traversal" << std::endl;
   bt.travMi ( twice ); cout << bt;
   bt.travMi ( inc );   cout << bt;
   std::cout << "post traversal" << std::endl;
   bt.travPo ( twice ); cout << bt;
   bt.travPo ( inc );   cout << bt;
   std::cout << "level traversal" << std::endl;
   bt.travLv ( twice ); cout << bt;
   bt.travLv ( inc );   cout << bt;
   Hailstone<T> hs; bt.travMi ( hs ); cout << bt;
   if (rand() % 2)
   {
   printf ( "\n  ==== Test %2d. Remove subtrees in the Tree\n", testID++ );
   while ( !bt.empty() ) {
      BinNodePosi<T> p = randomPosiInBinTree ( bt.root() ); //Ëæ»úÑ¡ÔñÒ»¸ö½Úµã
         printf ( "removing " ); std::cout << (int) p->data << " ...\n" ;
         printf ( "%d node(s) removed\n", bt.remove ( p ) ); 
         std::cout << bt ;
      } 
   } else {
      printf ( "\n  ==== Test %2d. Release subtrees in the Tree\n", testID++ );
      while ( !bt.empty() ) {
         BinNodePosi<T> p = randomPosiInBinTree ( bt.root() ); //Ëæ»úÑ¡ÔñÒ»¸ö½Úµã
            printf ( "releasing " ); std::cout << (int) p->data << " ...\n" ;
            BinTree<T>* S = bt.secede ( p );
            printf ( "%d node(s) released\n", S->size() ); 
            std::cout << bt ;
      }
   }
}

int main ( int argc, char* argv[] ) { //²âÊÔ¶þ²æÊ÷
   if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   srand ( ( unsigned int ) time ( NULL ) );
   testBinTree<int> ( atoi ( argv[1] ) ); //ÔªËØÀàÐÍ¿ÉÒÔÔÚÕâÀïÈÎÒâÑ¡Ôñ
   return 0;
}
