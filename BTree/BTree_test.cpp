#include "../print/print.cpp"
#include "BNode.h"
#include "BTree.cpp"
#include <iostream>
#define dice(X) (rand() % (X))

/******************************************************************************************
 * Test a BTree
 ******************************************************************************************/

template <typename T> void testBTree(int m, int n) {
  BTree<T> bt(m);
  while (bt.BTree<T>::size() < n) {
    T e = dice((T)n * 3); //[0, 3n)·¶Î§ÄÚµÄe
    switch (dice(3)) {
    case 0: { // ²éÕÒ£¬³É¹¦ÂÊ <= 33.3%
      printf("Searching for ");
      print(e);
      printf(" ... ");
      BNodePosi<T> p = bt.BTree<T>::search(e);
      printf(p ? "Found\n" : "Not found\n");
      break;
    }
    case 1: { // É¾³ý£¬³É¹¦ÂÊ <= 33.3%
      printf("Removing ");
      print(e);
      printf(" ... ");
      if (bt.BTree<T>::remove(e)) {
        printf("Done\n"), print(bt);
      } else
        printf("Not exists\n");
      break;
    }
    default: { // ²åÈë£¬³É¹¦ÂÊ == 100%
      printf("Inserting ");
      print(e);
      printf(" ... ");
      int oldSize = bt.size();
      if (bt.BTree<T>::insert(e)) {
        printf("Done\n"), print(bt);
      } else
        printf("Dup key\n");
      break;
    }
    }
  }
  // while (bt.size() > 0) {
  //   T e = dice((T)n * 3); //[0, 3n)·¶Î§ÄÚµÄe
  //   printf("Removing ");
  //   print(e);
  //   printf(" ... ");
  //   if (bt.BTree<T>::remove(e)) {
  //     printf("Done\n"), print(bt);
  //   } else
  //     printf("not exists\n");
  // }
}

/******************************************************************************************
 * ²âÊÔÖ÷Èë¿Ú
 ******************************************************************************************/
int main(int argc, char *argv[]) {
  if (3 > argc) {
    printf("Usage: %s <order of B-tree> <size of test>\a\a\n", argv[0]);
    return 1;
  }
  int m = atoi(argv[1]);
  if (m < 3) {
    printf("Make sure the order (%d) is no less than 3.\a\a\n", m);
    return 1;
  }
  int size = atoi(argv[2]);
  if (size < 0) {
    printf("Make sure the size (%d) is no less than 0.\a\a\n", size);
    return 1;
  }
  srand((unsigned int)time(NULL)); 
  // srand(3141592653); // ¹Ì¶¨ÖÖ×Ó
  testBTree<int>(atoi(argv[1]),
                 atoi(argv[2])); // ÔªËØÀàÐÍ¡¢±È½ÏÆ÷¿ÉÒÔÔÚÕâÀïÈÎÒâÑ¡Ôñ
  return 0;
}
