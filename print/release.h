#ifndef _CLEAN_
#define _CLEAN_

#include <typeinfo>

/******************************************************************************************
 * ÁÐ±í¡¢ÏòÁ¿µÈ½á¹¹ÄÚµÄ½ÚµãÖÐ£¬¿ÉÒÔ´æ·Å»ù±¾ÀàÐÍ»ò¹¹ÔìÀàÐÍ
 * °´ÕÕ±¾ÊéÔ¼¶¨£¬³öÓÚÐ§ÂÊµÄ¿¼ÂÇ£¬¶ÔÓÚºóÒ»Çé¿öÍ¨³£Ö»±£´æ¶ÔÏóµÄÖ¸Õë
 * Òò´Ë£¬ÔÚÖ÷Ìå½á¹¹Îö¹¹Ö®Ç°£¬ÐèÒªÊ×ÏÈÊÍ·ÅÕâÐ©³ÉÔ±¶ÔÏóËùÕ¼µÄ¿Õ¼ä
 * ´Ë´¦£¬½èÖúC++ÖÐÆ«ÌØ»¯¼¼ÊõÇø·ÖÉÏÊöÁ½ÖÖÇé¿ö£¬²¢×ö¶ÔÓ¦´¦Àí
 ******************************************************************************************/
template <typename T> struct Cleaner {
   static void clean( T x ) { //Ïàµ±ÓÚµÝ¹é»ù
#ifdef _DEBUG
      static int n = 0;
      if ( 7 > strlen( typeid( T ).name() ) ) { //¸´ÔÓÀàÐÍÒ»¸ÅºöÂÔ£¬Ö»Êä³ö»ù±¾ÀàÐÍ
         printf( "\t<%s>[%d]=", typeid( T ).name(), ++n );
         print( x );
         printf( " purged\n" );
      }
#endif
   }
};

template <typename T> struct Cleaner<T*> {
   static void clean( T* x ) {
      if ( x ) { delete x; } //Èç¹ûÆäÖÐ°üº¬Ö¸Õë£¬µÝ¹éÊÍ·Å
#ifdef _DEBUG
      static int n = 0;
      printf( "\t<%s>[%d] released\n", typeid( T* ).name(), ++n );
#endif
   }
};

template <typename T> void release( T x ) { Cleaner<T>::clean( x ); }
#endif // !_CLEAN_
