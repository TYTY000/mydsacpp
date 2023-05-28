#include <iostream>
template <typename K, typename V>    // e¡¢value
void Print::p(HashTable<K, V> &HT) { // ÒýÓÃ
  std::cout << boost::core::demangle(typeid(HT).name()) << " @ [" << &HT;
  printf("]*(%d)/%d:\n", HT.N, /* HT.lazyremove.size(), */ HT.M); // »ù±¾ÐÅÏ¢
  for (Rank i = 0; i < HT.M; i++) // Êä³öÍ°±àºÅ
    printf("  %4d  ", i);
  printf("\n");
  for (Rank i = 0; i < HT.M; i++) // Êä³öËùÓÐÔªËØ
    if (HT.dic[i])
      printf("-<%04d>-", HT.dic[i]->key); // ÑÝÊ¾ÓÃ£¬½öÊÊÓÃÓÚint
    // else if ( HT.lazyremove.find(i) ) printf ( "-<****>-" );
    else
      printf("--------");
  printf("\n");
  for (Rank i = 0; i < HT.M; i++) // Êä³öËùÓÐÔªËØ
    if (HT.dic[i])
      printf("    %c   ", HT.dic[i]->value); // ÑÝÊ¾ÓÃ£¬½öÊÊÓÃÓÚchar
    //      if (HT.dic[i]) printf("%8s", HT.dic[i]->value);
    //      //Õë¶ÔHuffman±àÂëÖÐÊ¹ÓÃµÄÉ¢ÁÐ±í
    // else if ( HT.lazyremove.find(i) ) printf ( "    *   " );
    else
      printf("        ");
  printf("\n");
}
