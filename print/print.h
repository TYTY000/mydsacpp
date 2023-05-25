/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-16 12:44:36
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-25 15:31:22
 */

#ifndef __PRINT__
#define __PRINT__

#include <cstdio> //²ÉÓÃC·ç¸ñ¾«Ï¸¿ØÖÆÊä³ö¸ñÊ½
#include <iostream>
// #include "huffman/huffChar.h" //Huffman³¬×Ö·û
// #include "../binTree/binTree.h"
// #include "Huffman/HuffTree.h" //HuffmanÊ÷
// #include "../BST/BST.h" //¶þ²æËÑË÷Ê÷
// #include "../AVL/AVL.h" //AVLÊ÷
// #include "../splayTree/splayTree.h" //ÉìÕ¹Ê÷
// #include "../RBTree/RBTree.h"//ºìºÚÊ÷
// #include "../BTree/BTree.h" //¶þ²æËÑË÷Ê÷
#include "../SkipList/Entry.h"
// #include "../SkipList/QuadList.h"
// #include "../SkipList/QuadNode.h"
// #include "../SkipList/SkipList.h"
#include "../hashtable/HashTable.h" //É¢ÁÐ±í
// #include "PQ_List/PQ_List.h" //»ùÓÚÁÐ±íÊµÏÖµÄÓÅÏÈ¼¶¶ÓÁÐ
// #include "PQ_ComplHeap/PQ_ComplHeap.h" //»ùÓÚÍêÈ«¶ÑÊµÏÖµÄÓÅÏÈ¼¶¶ÓÁÐ
// #include "PQ_LeftHeap/PQ_LeftHeap.h" //»ùÓÚ×óÊ½¶ÑÊµÏÖµÄÓÅÏÈ¼¶¶ÓÁÐ
// #include "graph/Graph.h" //Í¼
// #include "../graph/graph_matrix.h"

class Print {
public:
  static void p(int);
  static void p(unsigned int);
  static void p(size_t);
  static void p(float);
  static void p(double);
  static void p(char);
  // static void p ( HuffChar& ); //Huffman£¨³¬£©×Ö·û
  // static void p(VStatus); // Í¼¶¥µãµÄ×´Ì¬
  // static void p(EType);   // Í¼±ßµÄÀàÐÍ

  template <typename K, typename V> static void p(Entry<K, V> &);    // Entry
  // template <typename T> static void p(Quadlist<T> &);                // Quadlist
  // template <typename K, typename V> static void p(Skiplist<K, V> &); //
  // template <typename T> static void p( BinNode<T>& ); // BinTree½Úµã
  // template <typename T> static void p( BinTree<T>& ); //¶þ²æÊ÷
  // template <typename T> static void p( BTree<T>& ); // B-Ê÷
  // template <typename T> static void p( BST<T>& ); // BST
  // template <typename T> static void p( AVL<T>& ); // AVL
  // template <typename T> static void p( RBTree<T>& ); // RedBlack
  // template <typename T> static void p( SplayTree<T>& ); // Splay
   template <typename K, typename V> static void p( HashTable<K, V>& ); // Hashtable
   // template <typename T> static void p( PQ_List<T>& ); // PQ_List
   // template <typename T> static void p( PQ_ComplHeap<T>& ); // PQ_ComplHeap
   // template <typename T> static void p( PQ_LeftHeap<T>& ); // PQ_LeftHeap
   // template <typename Tv, typename Te> static void p( GraphMatrix<Tv, Te>& ); // Graph
  // PQ_List template <typename T> static void p( PQ_ComplHeap<T>& ); //
  // PQ_ComplHeap template <typename T> static void p( PQ_LeftHeap<T>& ); //
  // PQ_LeftHeap
  // template <typename Tv, typename Te>
  // static void p(GraphMatrix<Tv, Te> &); // Graph
  template <typename T>
  static void p(T &); // ÏòÁ¿¡¢ÁÐ±íµÈÖ§³Ötraverse()±éÀú²Ù×÷µÄÏßÐÔ½á¹¹
  template <typename T>
  static void p(T *s) // ËùÓÐÖ¸Õë
  {
    if (s)
      p(*s);
    else
      printf("<NULL>");
  } // Í³Ò»×ªÎªÒýÓÃ
};  // UniPrint

template <typename T> static void print(T *x) {
  if (x)
    print(*x);
  else
    printf(" <NULL>");
}
// template <typename T> static void print(Stack<T> *x) {
//   if (x)
//     std::cout << *x << std::endl;
//   else
//     printf(" <NULL>");
// }
template <typename T> static void print(T &x) { Print::p(x); }
template <typename T> static void print(const T &x) {
  Print::p(x);
} // for
  // Stack
static void print(char *x) {
  printf(" %s", x ? x : "<NULL>");
} // ×Ö·û´®ÌØ±ð´¦Àí
static void print(const char *x) {
  printf(" %s", x ? x : "<NULL>");
} // ×Ö·û´®ÌØ±ð´¦Àí
// #include "graph.h"
// #include "tree.h"
// #include "btree.h"
#endif // !__PRINT__
