#include "splayTree.cpp"
#include "../print/print.cpp"
#include <iostream>
using namespace std;

#define dice(X) (rand() % (X))

template <typename T> void testSplayPeriod(int n) { // ÖÜÆÚÐÔ·ÃÎÊ²âÊÔ
  SplayTree<T> splay;
  for (int i = 0; i < n; i++)
    splay.SplayTree<T>::insert((T)i);
  print(splay);
  for (int i = 0; i < n; i++) {
    splay.SplayTree<T>::search((T)i);
    print(splay);
  }
}

template <typename T> void testSplayRandom(Rank n) { // Ëæ»ú·ÃÎÊ²âÊÔ
  SplayTree<T> splay;
  while (splay.size() < n) {
    T e = dice((T)n * 3); //[0, 3n)·¶Î§ÄÚµÄe
    switch (dice(3)) {
    case 0: { // ²éÕÒ£¬³É¹¦ÂÊ <= 33.3%
      printf("Searching for ");
      print(e);
      printf(" ...\n");
      splay.SplayTree<T>::search(e)  ? printf("Found with"), print(splay.root()),
          printf("\n") : printf("Not found\n");
      break;
    }
    case 1: { // É¾³ý£¬³É¹¦ÂÊ <= 33.3%
      printf("Removing ");
      print(e);
      printf(" ...\n");
      if (splay.SplayTree<T>::remove(e))
        printf("Removal done\n");
      else
        print(e), printf(" not exists\n");
      break;
    }
    default: { // ²åÈë£¬³É¹¦ÂÊ == 100%
      printf("Inserting ");
      print(e);
      printf(" ...\n");
      splay.SplayTree<T>::insert(e);
      if (e == splay.root()->data)
        printf("Insertion done with"), print(splay.root()), printf("\n");
      else
        print(e), printf("duplicated");
      break;
    }
    }             // switch
    print(splay); // ÎÞÂÛµ÷ÓÃÄÄ¸ö½Ó¿Ú£¬Splay¶¼»á×ÔÎÒµ÷ÕûÐÎÌ¬£¬¹ÊÐèÍ³Ò»Êä³ö
  }               // while
  while (splay.size() > 0) {
    T e = dice((T)n * 3); //[0, 3n)·¶Î§ÄÚµÄe
    printf("Removing ");
    print(e);
    printf(" ...\n");
    splay.SplayTree<T>::remove(e) ? printf("Removal done\n"), print(splay) : print(e),
        printf(" not exists\n");
  }
} // ¿Îºó£ºÀûÓÃÕâÒ»½Ó¿Ú£¬Õë¶Ô²»Í¬·Ö²¼µÄ·ÃÎÊ£¬ÑéÖ¤¿ÎÉÏ¶ÔSplay·ÖÌ¯·ÖÎöµÄ½áÂÛ

int main(int argc, char *argv[]) { // ²âÊÔÖ÷Èë¿Ú
  if (2 > argc) {
    printf("Usage: %s <size of test>\a\a\n", argv[0]);
    return 1;
  }
  srand((unsigned int)time(NULL)); // Ëæ»úÖÖ×Ó
  // srand( 31415926 ); //¹Ì¶¨ÖÖ×Ó£¨¼ÙÖÖ×Ó£¬µ÷ÊÔÓÃ£©
  testSplayRandom<int>(atoi(argv[1])); // ÔªËØÀàÐÍ¿ÉÒÔÔÚÕâÀïÈÎÒâÑ¡Ôñ
  testSplayPeriod<int>(atoi(argv[1])); // ÔªËØÀàÐÍ¿ÉÒÔÔÚÕâÀïÈÎÒâÑ¡Ôñ
  return 0;
}
