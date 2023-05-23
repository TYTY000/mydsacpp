#include "../print/hashtable.h"
#include "./HashTable.cpp"
#include <iostream>
using namespace std;
#define dice(X) (rand() % (X))

template <typename K, typename V> // key¡¢value
void testHashTable(Rank n) {
  HashTable<K, V> ht(n);
  print(ht);
  while (ht.size() < 4 * n) {
    K key = dice((K)n * 12);
    V v = (V)'A' + dice(26); // ÔÚ[0, 2n)*['A'~'Z']·¶Î§ÄÚµÄ´ÊÌõ
    printf("Inserting <");
    print(key);
    printf("(%04d)", hashCode(key));
    printf(" :");
    print(v);
    printf(" >\n");
    if (ht.put(key, v)) {
      printf("Done\n"), print(ht);
    } else
      printf("Dup key\n");
  }
  while (ht.size() < 4 * n) {
    printf("\n");
    switch (dice(2)) {
    case 0: {                  // ²éÕÒ£¬³É¹¦ÂÊ <= 33.3%
      K key = dice((K)n * 12); //[0, 3n)·¶Î§ÄÚµÄkey
      printf("Searching ");
      print(key);
      printf("(%04d) :\n", hashCode(key));
      V *pValue = ht.get(key);
      if (pValue) {
        printf("Found with "), print(*pValue);
      } else
        printf("Not found");
      printf("\n");
      break;
    }
    case 1: {                  // É¾³ý£¬³É¹¦ÂÊ <= 33.3%
      K key = dice((K)n * 12); //[0, 3n)·¶Î§ÄÚµÄkey
      printf("Removing ");
      print(key);
      printf("(%04d) :\n", hashCode(key));
      if (ht.remove(key)) {
        printf("Done\n"), print(ht);
      } else
        printf("Entry not exists\n");
      break;
    }
    // default: { // ²åÈë£¬³É¹¦ÂÊ == 100%
    //   K key = dice((K)n * 12);
    //   V v = (V)'A' + dice(26); // ÔÚ[0, 2n)*['A'~'Z']·¶Î§ÄÚµÄ´ÊÌõ
    //   printf("Inserting <");
    //   print(key);
    //   printf("(%04d)", hashCode(key));
    //   printf(" :");
    //   print(v);
    //   printf(" >\n");
    //   if (ht.put(key, v)) {
    //     printf("Done\n"), print(ht);
    //   } else
    //     printf("Dup key\n");
    //   break;
    // }
    } // switch
  }   // while
  while (ht.size() > 0) {
    printf("\n");
    K key = dice((K)n * 12); //[0, 3n)·¶Î§ÄÚµÄkey
    printf("Removing ");
    print(key);
    printf(" :\n");
    if (ht.remove(key)) {
      printf("Done\n"), print(ht);
    } else
      printf("Entry not exists\n");
  }
}

/******************************************************************************************
 * Ö÷³ÌÐò
 ******************************************************************************************/
int main(int argc, char *argv[]) {
  if (2 > argc) {
    printf("Usage: %s <size of test>\a\a\n", argv[0]);
    return 1;
  }
  srand((unsigned int)time(NULL)); // Ëæ»úÖÖ×Ó
  // srand( 31415926 ); //¹Ì¶¨ÖÖ×Ó£¨¼ÙÖÖ×Ó£¬µ÷ÊÔÓÃ£©
  testHashTable<int, char>(atoi(argv[1])); // ÔªËØÀàÐÍ¿ÉÒÔÔÚÕâÀïÈÎÒâÑ¡Ôñ
  return 0;
}
