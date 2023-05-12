#ifndef __VECTOR_MANIP__
#define __VECTOR_MANIP__

#include <iostream>
#include <random>
#include "vector_sort.h"

template <typename T> void Vector<T>::sort( Rank lo, Rank hi ) {
  switch ( rand() % 3 ) {
    case 1 : bubbleSort( lo, hi );    break;
    case 2 : selectionSort( lo, hi ); break;
    default : mergeSort( lo, hi );    break;
  }
}

template <typename T>
void Vector<T>::unsort ( Rank lo, Rank hi )
{
  T* S = _elem + lo;
  for (Rank i = hi - lo; i > 0; i--)
    std::swap( S[i - 1], S[rand() % i] );   
}

template <typename T>
Rank Vector<T>::insert( Rank r, const T& e )
{
  expand();
  for (Rank i = _size; i > r; i--)
    _elem[i] = _elem[i - 1];   
  _elem[r] = e;_size++;
  return r;
}

template <typename T>
Rank Vector<T>::remove( Rank lo, Rank hi )
{
  if ( lo == hi ) return 0;
  while ( hi < _size ) _elem[lo++] = _elem[hi++];
  _size -= ( hi - lo );
  shrink();
  return hi - lo;
}

template <typename T>
T Vector<T>::remove( Rank r )
{
  T old = _elem[r];
  remove( r, r+1 );
  return old;
}


template <typename T>
Rank Vector<T>::deduplicate()
{
  Rank oldSize = _size;
  Rank i = 1;
  std::cout << "remove : ";
  while ( i < _size ) 
    if ( find ( _elem[i], 0, i ) == -1 ) 
      i++; 
    else std::cout << remove(i) << '\t';
  std::cout << '\n';
  return oldSize - _size;
}

template <typename T>
Rank Vector<T>::uniquify()
{
  Rank i = 0, j = 0;
  std::cout << "remove : ";
  while ( ++j < _size )
    if ( _elem[i] != _elem [j] ) 
      _elem[++i] = _elem[j];
    else 
      std::cout << _elem[i] << '\t';
  _size = ++i; shrink();
  std::cout << '\n';
  return j - i;
}

template <typename T>
Rank Vector<T>::disordered()
{
  int cnt = 0;
  for (Rank i = 1; i < _size; i++)
    if( _elem[i - 1] > _elem[i] ) cnt++;   
  return cnt;
}

template <typename T>
void Vector<T>::traverse ( void (* visit) ( T& ) )
{
  for (Rank i = 0; i < _size; i++) {
    visit ( _elem[i] );
  }
}

template <typename T> template <typename VST> 
void Vector<T>::traverse ( VST& visit )
{
  for (Rank i = 0; i < _size; i++) {
    visit ( _elem[i] );
  }
}
#endif // !__Vector_MANIP__
