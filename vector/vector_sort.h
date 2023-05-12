#ifndef __VECTOR_SORT__
#define __VECTOR_SORT__

#include <iostream>

template<typename T>
void Vector<T>::bubbleSort ( Rank lo, Rank hi )
{
  std::cout << "BubbleSort [" << lo << " , " << hi << ") " << std::endl;
  for (Rank last; lo < hi; hi = last )
    for (Rank i = ( last = lo ) + 1 ; i < hi; i++) 
      if ( _elem [i-1] > _elem [i])
        std::swap ( _elem[i-1], _elem[last = i]);
}

template <typename T>
void Vector<T>::selectionSort( Rank lo, Rank hi ) {
  std::cout << "SelectionSort [" << lo << " , " << hi << ") " << std::endl;
  while ( lo < --hi )
    std::swap( _elem[maxItem( lo, hi )], _elem[hi] );
}

template <typename T>
void Vector<T>::mergeSort( Rank lo, Rank hi ) {
   if ( hi - lo < 2 ) return;
   Rank mi = ( lo + hi ) / 2;
   mergeSort( lo, mi ); mergeSort( mi, hi );
   merge( lo, mi, hi );
}

template <typename T>
void Vector<T>::merge( Rank lo, Rank mi, Rank hi ) {
  std::cout << "MergeSort [" << lo << " , " << hi << ") " << std::endl;
  Rank i = 0; T* A = _elem + lo; 
  Rank j = 0, lb = mi - lo; T* B = new T[lb];
  for ( Rank i = 0; i < lb; i++ ) B[i] = A[i];
  Rank k = 0, lc = hi - mi; T* C = _elem + mi;
  while ( ( j < lb ) && ( k < lc ) )
    A[i++] = ( B[j] <= C[k] ) ? B[j++] : C[k++];
  while ( j < lb )
    A[i++] = B[j++];
  delete[] B;
}

#endif // !__VECTOR_SORT__
