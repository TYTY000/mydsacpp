#include "bitmap.h" //Ê¹ÓÃÎ»Í¼¼ÇÂ¼·ÖÖ§×ªÏò
#include "./release.h"

#define ROOT 0
#define L_CHILD 1
#define R_CHILD -1*L_CHILD

#include <boost/core/demangle.hpp>
/******************************************************************************************
 * »ù´¡BinTree
 ******************************************************************************************/
template <typename T> //ÔªËØÀàÐÍ
void Print::p ( BinTree<T> & bt ) { //ÒýÓÃ
  std::cout << boost::core::demangle(typeid ( bt ).name()) << "\t@  " << &bt << "\tsize = " << bt.size() << std::endl; //»ù±¾ÐÅÏ¢
   Bitmap* branchType = new Bitmap; //¼ÇÂ¼µ±Ç°½Úµã×æÏÈµÄ·½Ïò
   printBinTree ( bt.root(), -1, ROOT, branchType ); //Ê÷×´½á¹¹
   release ( branchType ); printf ( "\n" );
}

/******************************************************************************************
 * »ùÓÚBinTreeÊµÏÖµÄBST
 ******************************************************************************************/
template <typename T> //ÔªËØÀàÐÍ
void Print::p ( BST<T> & bt ) { //ÒýÓÃ
  std::cout << boost::core::demangle(typeid ( bt ).name()) << "\t@  " << &bt << "\tsize = " << bt.size() << std::endl; //»ù±¾ÐÅÏ¢
   Bitmap* branchType = new Bitmap; //¼ÇÂ¼µ±Ç°½Úµã×æÏÈµÄ·½Ïò
   printBinTree ( bt.root(), -1, ROOT, branchType ); //Ê÷×´½á¹¹
   release ( branchType ); printf ( "\n" );
}

/******************************************************************************************
 * »ùÓÚBSTÊµÏÖµÄAVL
 * ÆäÖÐµ÷ÓÃµÄBinNodeµÄ´òÓ¡Àý³Ì£¬¿ÉÒÔÏÔÊ¾BF×´Ì¬
 ******************************************************************************************/
// template <typename T> //ÔªËØÀàÐÍ
// void print::p ( AVL<T> & avl ) { //ÒýÓÃ
  // std::cout << boost::core::demangle(typeid ( avl ).name()) << "\t@  " << &avl << "\tsize = " << avl.size() << std::endl; //»ù±¾ÐÅÏ¢
//    Bitmap* branchType = new Bitmap; //¼ÇÂ¼µ±Ç°½Úµã×æÏÈµÄ·½Ïò
//    printBinTree ( avl.root(), -1, ROOT, branchType ); //Ê÷×´½á¹¹
//    release ( branchType ); printf ( "\n" );
// }

/******************************************************************************************
 * »ùÓÚBSTÊµÏÖµÄRedBlack
 * ÆäÖÐµ÷ÓÃµÄBinNodeµÄ´òÓ¡Àý³Ì£¬¿ÉÒÔÏÔÊ¾BF×´Ì¬
 ******************************************************************************************/
// template <typename T> //ÔªËØÀàÐÍ
// void print::p ( RedBlack<T> & rb ) { //ÒýÓÃ
   // printf ( "%s[%d]*%d:\n", boost::core::demangle(typeid ( rb).name()), (int) &rb, rb.size() << std::endl; //»ù±¾ÐÅÏ¢
//    Bitmap* branchType = new Bitmap; //¼ÇÂ¼µ±Ç°½Úµã×æÏÈµÄ·½Ïò
//    printBinTree ( rb.root(), -1, ROOT, branchType ); //Ê÷×´½á¹¹
//    release ( branchType ); printf ( "\n" );
// }

/******************************************************************************************
 * »ùÓÚBSTÊµÏÖµÄSplay
 * ¼øÓÚSplay²»±ØÉèÖÃbfÖ®ÀàµÄ¸½¼Ó±êÊ¶£¬Æä´òÓ¡Àý³ÌÓëBSTÍêÈ«Ò»ÖÂ
 ******************************************************************************************/
template <typename T> //ÔªËØÀàÐÍ
void Print::p ( SplayTree<T> & bt ) { //ÒýÓÃ
  std::cout << boost::core::demangle(typeid ( bt ).name()) << "\t@  " << &bt << "\tsize = " << bt.size() << std::endl; //»ù±¾ÐÅÏ¢
   Bitmap* branchType = new Bitmap; //¼ÇÂ¼µ±Ç°½Úµã×æÏÈµÄ·½Ïò
   printBinTree ( bt.root(), -1, ROOT, branchType ); //Ê÷×´½á¹¹
   release ( branchType ); printf ( "\n" );
}

/******************************************************************************************
 * ¶þ²æÊ÷¸÷ÖÖÅÉÉúÀàµÄÍ³Ò»´òÓ¡
 ******************************************************************************************/
template <typename T> //ÔªËØÀàÐÍ
static void printBinTree ( BinNodePosi<T> bt, int depth, int type, Bitmap* bType ) {
   if ( !bt ) return;
   if ( -1 < depth ) //ÉèÖÃµ±Ç°²ãµÄ¹ÕÏò±êÖ¾
      R_CHILD == type ? bType->set ( depth ) : bType->clear ( depth );
   printBinTree ( bt->rc, depth + 1, R_CHILD, bType ); //ÓÒ×ÓÊ÷£¨ÔÚÉÏ£©
   print ( bt ); printf ( " *" );
   for ( int i = -1; i < depth; i++ ) //¸ù¾ÝÏàÁÚ¸÷²ã
      if ( ( 0 > i ) || bType->test ( i ) == bType->test ( i + 1 ) ) //µÄ¹ÕÏòÊÇ·ñÒ»ÖÂ£¬¼´¿ÉÈ·¶¨
         printf ( "      " ); //ÊÇ·ñÓ¦¸Ã
      else  printf ( "©¦    " ); //´òÓ¡ºáÏß
   switch ( type ) {
      case  R_CHILD  :  printf ( "©°©¤" );  break;
      case  L_CHILD  :  printf ( "©¸©¤" );  break;
      default        :  printf ( "©¤©¤" );  break; //root
   }
   print ( bt );
#if defined(DSA_HUFFMAN)
   if ( IsLeaf ( *bt ) ) bType->print ( depth + 1 ); //Êä³öHuffman±àÂë
#endif
   printf ( "\n" );
   printBinTree ( bt->lc, depth + 1, L_CHILD, bType ); //×ó×ÓÊ÷£¨ÔÚÏÂ£©
}



/*DSA*/#define HeightUpdated(x) /*¸ß¶È¸üÐÂ³£¹æÌõ¼þ*/ \
/*DSA*/        ( (x).height == 1 + max( stature( (x).lc ), stature( (x).rc ) ) )
#define Balanced( x ) ( stature( ( x ).lc ) == stature( ( x ).rc ) ) //ÀíÏëÆ½ºâÌõ¼þ
#define BalFac( x ) ( stature( ( x ).lc ) - stature( ( x ).rc ) ) //Æ½ºâÒò×Ó
#define AvlBalanced( x ) ( ( -2 < BalFac( x ) ) && ( BalFac( x ) < 2 ) ) // AVLÆ½ºâÌõ¼þ
template <typename T> void Print::p ( BinNode<T>& node ) {
   p ( node.data ); //ÊýÖµ
   /******************************************************************************************
    * height & NPL
    ******************************************************************************************/
#if   defined(DSA_LEFTHEAP)
   printf ( "(%2d)", node.npl ); //NPL
#elif defined(DSA_BST)
   printf ( "(%2d)", node.height ); //¸ß¶È
#elif defined(DSA_AVL)
   printf ( "(%2d)", node.height ); //¸ß¶È
#elif defined(DSA_REDBLACK)
   printf ( "(%2d)", node.height ); //¸ß¶È
#elif defined(DSA_SPLAY)
   printf ( "(%2d)", node.height ); //¸ß¶È
#endif
   /******************************************************************************************
    * ¸¸×ÓÁ´½ÓÖ¸Õë
    ******************************************************************************************/
   printf (
      ( node.lc && &node != node.lc->parent ) ||
      ( node.rc && &node != node.rc->parent ) ?
      "@" : " "
   );
   /******************************************************************************************
    * ½ÚµãÑÕÉ«
    ******************************************************************************************/
#if defined(DSA_REDBLACK)
   printf ( node.color == RB_BLACK ? "B" : " " ); //£¨ºöÂÔºì½Úµã£©
#endif
   /******************************************************************************************
    * ¸¸×Ó£¨ºÚ£©¸ß¶È¡¢NPLÆ¥Åä
    ******************************************************************************************/
#if   defined(DSA_PQ_COMPLHEAP)
   //¸ß¶È²»±ØÆ¥Åä
#elif defined(DSA_PQ_LEFTHEAP)
   printf ( //NPL
      ( node.rc && ( node.npl != 1 + node.rc->npl ) ) ||
      ( node.lc && ( node.npl >  1 + node.lc->npl ) ) ?
      "%%" : " "
   );
#elif defined(DSA_REDBLACK)
   printf ( BlackHeightUpdated ( node ) ? " " : "!" ); //ºÚ¸ß¶È
#else
   printf ( HeightUpdated ( node ) ? " " : "!" ); //£¨³£¹æ£©¸ß¶È
#endif
   /******************************************************************************************
    * ×óÓÒÆ½ºâ
    ******************************************************************************************/
#if defined(DSA_AVL)
   if ( !AvlBalanced ( node ) ) printf ( "X" ); //AVLÆ½ºâ
   else if ( 0 < BalFac ( node ) ) printf ( "\\" ); //AVLÆ½ºâ
   else if ( BalFac ( node ) < 0 ) printf ( "/" ); //AVLÆ½ºâ
   else printf ( "-" ); //AVLÆ½ºâ
#elif defined(DSA_REDBLACK)
   if ( !Balanced ( node ) ) printf ( "X" ); //RBÆ½ºâ
   else if ( 0 < BalFac ( node ) ) printf ( "\\" ); //RBÆ½ºâ
   else if ( BalFac ( node ) < 0 ) printf ( "/" ); //RBÆ½ºâ
   else printf ( "-" ); //RBÆ½ºâ
#else
   //Æ½ºâÎÞËùÎ½
#endif
}
