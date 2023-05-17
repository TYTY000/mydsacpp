/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-16 12:44:36
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-16 15:37:56
 */

#ifndef __PRINT__
#define __PRINT__

#include <iostream>
#include <cstdio> //²ÉÓÃC·ç¸ñ¾«Ï¸¿ØÖÆÊä³ö¸ñÊ½
// #include "huffman/huffChar.h" //Huffman³¬×Ö·û
// #include "BinTree/BinTree.h" //¶þ²æÊ÷
// #include "Huffman/HuffTree.h" //HuffmanÊ÷
// #include "BST/BST.h" //¶þ²æËÑË÷Ê÷
// #include "AVL/AVL.h" //AVLÊ÷
// #include "Splay/Splay.h" //ÉìÕ¹Ê÷
// #include "redBlack/RedBlack.h" //ºìºÚÊ÷
// #include "BTree/BTree.h" //¶þ²æËÑË÷Ê÷
// #include "Entry/Entry.h" //´ÊÌõ
// #include "Skiplist/Quadlist.h" //ËÄ²æ±í
// #include "Skiplist/Skiplist.h" //Ìø×ª±í
// #include "Hashtable/Hashtable.h" //É¢ÁÐ±í
// #include "PQ_List/PQ_List.h" //»ùÓÚÁÐ±íÊµÏÖµÄÓÅÏÈ¼¶¶ÓÁÐ
// #include "PQ_ComplHeap/PQ_ComplHeap.h" //»ùÓÚÍêÈ«¶ÑÊµÏÖµÄÓÅÏÈ¼¶¶ÓÁÐ
// #include "PQ_LeftHeap/PQ_LeftHeap.h" //»ùÓÚ×óÊ½¶ÑÊµÏÖµÄÓÅÏÈ¼¶¶ÓÁÐ
// #include "graph/Graph.h" //Í¼
#include "../graph/graph_matrix.h"


class Print {
public:
   static void p ( int );
   static void p ( unsigned int );
   static void p ( size_t );
   static void p ( float );
   static void p ( double );
   static void p ( char );
   // static void p ( HuffChar& ); //Huffman£¨³¬£©×Ö·û
   static void p ( VStatus ); //Í¼¶¥µãµÄ×´Ì¬
   static void p ( EType ); //Í¼±ßµÄÀàÐÍ

   // template <typename K, typename V> static void p( Entry<K, V>& ); // Entry
   // template <typename T> static void p( BinNode<T>& ); // BinTree½Úµã
   // template <typename T> static void p( BinTree<T>& ); //¶þ²æÊ÷
   // template <typename T> static void p( BTree<T>& ); // B-Ê÷
   // template <typename T> static void p( BST<T>& ); // BST
   // template <typename T> static void p( AVL<T>& ); // AVL
   // template <typename T> static void p( RedBlack<T>& ); // RedBlack
   // template <typename T> static void p( Splay<T>& ); // Splay
   // template <typename T> static void p( Quadlist<T>& ); // Quadlist
   // template <typename K, typename V> static void p( Skiplist<K, V>& ); // Skiplist
   // template <typename K, typename V> static void p( Hashtable<K, V>& ); // Hashtable
   // template <typename T> static void p( PQ_List<T>& ); // PQ_List
   // template <typename T> static void p( PQ_ComplHeap<T>& ); // PQ_ComplHeap
   // template <typename T> static void p( PQ_LeftHeap<T>& ); // PQ_LeftHeap
   template <typename Tv, typename Te> static void p( GraphMatrix<Tv, Te>& ); // Graph
   template <typename T> static void p( T& ); //ÏòÁ¿¡¢ÁÐ±íµÈÖ§³Ötraverse()±éÀú²Ù×÷µÄÏßÐÔ½á¹¹
   template <typename T> static void p( T* s ) //ËùÓÐÖ¸Õë
   { s ? p( *s ) : printf( "<NULL>" ); } //Í³Ò»×ªÎªÒýÓÃ
}; //UniPrint

template <typename T> static void print ( T* x ) {  x ? print ( *x ) : printf ( " <NULL>" );  }
template <typename T> static void print ( T& x ) {  Print::p ( x );  }
template <typename T> static void print ( const T& x ) {  Print::p ( x );  } //for Stack
static void print ( char* x ) {  printf ( " %s", x ? x : "<NULL>" );  } //×Ö·û´®ÌØ±ð´¦Àí
static void print ( const char* x ) {  printf ( " %s", x ? x : "<NULL>" );  } //×Ö·û´®ÌØ±ð´¦Àí

#include <boost/core/demangle.hpp>
template <typename Tv, typename Te> //¶¥µãÀàÐÍ¡¢±ßÀàÐÍ
void Print::p ( GraphMatrix<Tv, Te>& s ) { //ÒýÓÃ
   Rank inD = 0; for ( Rank i = 0; i < s.n; i++ ) inD += s.inDegree ( i );
   Rank outD = 0; for ( Rank i = 0; i < s.n; i++ ) outD += s.outDegree ( i );
   std::cout << boost::core::demangle( typeid(s).name() ) << "\t " << "\tvertexes: " << s.n << "  edges: " << s.e << std::endl; //»ù±¾ÐÅÏ¢
// ±êÌâÐÐ
   print ( s.n ); printf ( " " ); print ( inD ); printf ( "|" );
   for ( Rank i = 0; i < s.n; i++ )
  {
    print ( s.vertex ( i ) ); printf ( "[" ); print ( s.status ( i ) ); printf ( "] " ); 
  }
   printf ( "\n" );
// ±êÌâÐÐ£¨Ðø£©
   print ( outD ); printf ( " " ); print ( s.e ); printf ( "|" );
   for ( Rank i = 0; i < s.n; i++ ) { print ( s.inDegree ( i ) ); printf ( " " ); }
   printf ( "| dTime fTime Parent Weight\n" );
// Ë®Æ½·Ö¸ôÏß
   printf ( "-----------+" ); for ( Rank i = 0; i < s.n; i++ ) printf ( "------" );
   printf ( "+----------------------------\n" );
// ÖðÐÐÊä³ö¸÷¶¥µã
   for ( Rank i = 0; i < s.n; i++ ) {
      print ( s.vertex ( i ) ); printf ( "[" ); print ( s.status ( i ) ); printf ( "] " ); print ( s.outDegree ( i ) ); printf ( "|" );
      for ( Rank j = 0; j < s.n; j++ )
         if ( s.exists ( i, j ) ) {
        print ( s.edge ( i, j ) ); print ( s.type ( i, j ) ); }
         else printf ( "     ." );
      printf ( "| " ); print ( s.dTime ( i ) ); printf ( " " ); print ( s.fTime ( i ) );
      printf ( "     " ); if ( -1 == s.parent ( i ) ) print ( "^" ); else print ( s.vertex ( s.parent ( i ) ) );
      printf ( "  " ); if ( INT_MAX > s.priority ( i ) ) print ( s.priority ( i ) ); else print ( " INF" );
      printf ( "\n" );
   }
   printf ( "\n" );
}




#endif // !__PRINT__
