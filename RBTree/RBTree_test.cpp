#include "../print/print.cpp"
#include "RBTree.h"
#include <iostream>
#define DSA_REDBLACK 1
using namespace std;

#define dice(X) (rand() % (X))

template <typename T> void testRedBlack(Rank n) {
  RBTree<T> rb;
  // for ( int i = 0; i < 256; i++ ) {
  //    int e = i % 2 ? i : -i;
  //    printf("Inserting "); print(e); printf(" ...\n");
  //    BinNodePosi<T> p = rb.insert(e);
  //    if ( p->data != e) { print(p->data); printf(" <> "); print(e);
  //    printf("\n"); } printf("Done with"), print(p), printf("\n"), print(rb);
  // }
  // return;
  while (rb.size() < n) {
    T e = dice((T)n * 3); //[0, 3n)·¶Î§ÄÚµÄe
    switch (dice(6)) {
    case 0: { // ²éÕÒ£¨¸ÅÂÊ = 1/6£©
      printf("Searching for ");
      print(e);
      printf(" ...\n");
      BinNodePosi<T> p = rb.search(e);
      p ? printf("Found with"), print(p), printf("\n") : printf("Not found\n");
      break;
    }
    case 1:
    case 2: { // É¾³ý£¨¸ÅÂÊ = 2/6)
      printf("Removing ");
      print(e);
      printf(" ...\n");
      if (rb.remove(e)) {
        printf("Done\n"), print(rb);
      } else
        printf("Not exists\n");
      break;
    }
    default: { // ²åÈë£¨¸ÅÂÊ = 3/6)
      printf("Inserting ");
      print(e);
      printf(" ...\n");
      BinNodePosi<T> p = rb.insert(e);
      if (p->data != e) {
        print(p->data);
        printf(" <> ");
        print(e);
        printf("\n");
      }
      printf("Done with"), print(p), printf("\n"), print(rb);
      break;
    }
    }
  }
  while (rb.size() > 0) {
    T e = dice((T)n * 3); //[0, 3n)·¶Î§ÄÚµÄe
    printf("Removing ");
    print(e);
    printf(" ...\n");
    if (rb.remove(e)) {
      printf("Done\n"), print(rb);
    } else
      printf("Not exists\n");
  }
}

/******************************************************************************************
 * ²âÊÔÖ÷Èë¿Ú
 ******************************************************************************************/
int main(int argc, char *argv[]) {
  if (2 > argc) {
    printf("Usage: %s <size of test>\a\a\n", argv[0]);
    return 1;
  }
  srand((unsigned int)time(NULL)); // Ëæ»úÖÖ×Ó
  // srand( 31415926 ); //¹Ì¶¨ÖÖ×Ó£¨¼ÙÖÖ×Ó£¬µ÷ÊÔÓÃ£©
  testRedBlack<int>(atoi(argv[1])); // ÔªËØÀàÐÍ¿ÉÒÔÔÚÕâÀïÈÎÒâÑ¡Ôñ
  return 0;
}
