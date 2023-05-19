#ifndef __VECTOR_INQUIRY__
#define __VECTOR_INQUIRY__

template <typename T>
Rank Vector<T>::find( const T& e, Rank lo, Rank hi ) const 
{
  while (  ( lo < hi -- ) && ( _elem[hi] != e ) );
  return hi;
}

#include "../fib/fib.h"

template <typename T>
static Rank fibSearch( T* A, const T& e, Rank lo, Rank hi )
{
  Fib fib( hi - lo );
  while ( hi > lo )
  {
    while ( hi - lo < fib.get() ) fib.prev();
    Rank mi = lo + fib.get() - 1;
    if ( e < A[mi] )      hi = mi;
    else lo = mi + 1;
  }
  return lo-1;
}

template <typename T>
Rank Vector<T>::search( const T& e, Rank lo, Rank hi ) const 
{
  return fibSearch( _elem, e, lo, hi );
}


#endif // !__Vector_INQUIRY__
