#include "print.h"
#include "./release.h"
#include <iostream>
void Print::p( int e ) { printf( " %04d", e ); }
void Print::p( unsigned int e ) { printf( " %04d", e ); }
void Print::p( size_t e ) { p( (int)e ); } // RankÐÍ0xFFFFFFFFÔÚ´òÓ¡Ç°ÏÈ×ª»»Îª-1£¬ÒÔ±ã¹Û²ì
void Print::p( float e ) { printf( " %4.3f", e ); }
void Print::p( double e ) { printf( " %4.3f", e ); }
void Print::p( char e ) { printf( " %c", ( 31 < e ) ? e : '$' ); }
template <typename T> static bool lt( T* a, T* b ) { return lt (*a, *b); }
template <typename T> static bool lt( T& a, T& b ) { return a < b; }
template <typename T> static bool eq( T* a, T* b ) { return eq (*a, *b); }
template <typename T> static bool eq( T& a, T& b ) { return a == b; }
// void Print::p( VStatus e ) {
//    switch ( e ) {
//       case UNDISCOVERED:   printf ( "U" ); break;
//       case DISCOVERED:     printf ( "D" ); break;
//       case VISITED:        printf ( "V" ); break;
//       default:             printf ( "X" ); break;
//    }
// }
// void Print::p( EType e ) {
//    switch ( e ) {
//       case UNDETERMINED:   printf ( "U" ); break;
//       case TREE:           printf ( "T" ); break;
//       case CROSS:          printf ( "C" ); break;
//       case BACKWARD:       printf ( "B" ); break;
//       case FORWARD:        printf ( "F" ); break;
//       default:             printf ( "X" ); break;
//    }
// }
#include "./tree.h"
// #include "./skiplist.h"
// #include "./hashtable.h"
// #include "./graph.h"
// #include "btree.h"
