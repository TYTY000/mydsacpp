
#include "bitmap.h" //Ê¹ÓÃÎ»Í¼¼ÇÂ¼·ÖÖ§×ªÏò
/******************************************************************************************
 * BTree´òÓ¡£¨Èë¿Ú£©
 ******************************************************************************************/
template <typename T> //ÔªËØÀàÐÍ
void Print::p ( BTree<T> & bt ) { //ÒýÓÃ
  std::cout << boost::core::demangle(typeid ( bt ).name()) << "\t@  " << &bt << "\tsize = " << bt.size() << std::endl; //»ù±¾ÐÅÏ¢
   Bitmap* leftmosts = new Bitmap; //¼ÇÂ¼µ±Ç°½Úµã×æÏÈµÄ·½Ïò
   Bitmap* rightmosts = new Bitmap; //¼ÇÂ¼µ±Ç°½Úµã×æÏÈµÄ·½Ïò
   printBTree ( bt.root(), 0, true, true, leftmosts, rightmosts ); //Êä³öÊ÷×´½á¹¹
   release ( leftmosts ); release ( rightmosts ); printf ( "\n" );
}

/******************************************************************************************
 * BTree´òÓ¡£¨µÝ¹é£©
 ******************************************************************************************/
template <typename T> //ÔªËØÀàÐÍ
static void printBTree ( BNodePosi<T> bt, int depth, bool isLeftmost, bool isRightmost, Bitmap* leftmosts, Bitmap* rightmosts ) {
   if ( !bt ) return;
   isLeftmost ? leftmosts->set ( depth ) : leftmosts->clear ( depth ); //ÉèÖÃ»òÇå³ýµ±Ç°²ãµÄ¹ÕÏò±êÖ¾
   isRightmost ? rightmosts->set ( depth ) : rightmosts->clear ( depth ); //ÉèÖÃ»òÇå³ýµ±Ç°²ãµÄ¹ÕÏò±êÖ¾
   int k = bt->child.size() - 1; //ÕÒµ½µ±Ç°½ÚµãµÄ×îÓÒ²àº¢×Ó£¬²¢
   printBTree ( bt->child[k], depth + 1, false, true, leftmosts, rightmosts ); //µÝ¹éÊä³öÖ®
   /*DSA*/bool parentOK = false; BNodePosi<T> p = bt->parent;
   /*DSA*/if ( !p ) parentOK = true;
   /*DSA*/else for ( Rank i = 0; i < p->child.size(); i++ ) if ( p->child[i] == bt ) parentOK = true;
   while ( 0 < k-- ) { //×ÔÓÒÏò×ó£¬Êä³ö¸÷×ÓÊ÷¼°ÆäÓÒ²àµÄ¹Ø¼üÂë
      /*DSA*/printf ( parentOK ? " " : "X" );
      print ( bt->key[k] ); printf ( " *>" );
      for ( int i = 0; i < depth; i++ ) //¸ù¾ÝÏàÁÚ¸÷²ã
         ( leftmosts->test ( i ) && leftmosts->test ( i + 1 ) || rightmosts->test ( i ) && rightmosts->test ( i + 1 ) ) ? //µÄ¹ÕÏòÊÇ·ñÒ»ÖÂ£¬¼´¿ÉÈ·¶¨
         printf ( "      " ) : printf ( "©¦    " ); //ÊÇ·ñÓ¦¸Ã´òÓ¡ºáÏòÁª½ÓÏß
      if ( ( ( 0 == depth && 1 < bt->key.size() ) || !isLeftmost && isRightmost ) && bt->key.size() - 1 == k ) printf ( "©°©¤" );
      else if ( ( ( 0 == depth && 1 < bt->key.size() ) || isLeftmost && !isRightmost ) && 0 == k )            printf ( "©¸©¤" );
      else                                                                                               printf ( "©À©¤" );
      print ( bt->key[k] ); printf ( "\n" );
      printBTree ( bt->child[k], depth + 1, 0 == k, false, leftmosts, rightmosts ); //µÝ¹éÊä³ö×ÓÊ÷
   }
}
