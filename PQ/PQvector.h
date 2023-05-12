/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-12 08:39:16
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-12 11:34:28
 */

#ifndef __PQ_VECTOR__
#define __PQ_VECTOR__

#include "./PQ.h"
#include "../vector/vector.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <ostream>

template <typename T>
    Rank percolateDown( T* A, Rank , Rank );
template <typename T>
    Rank percolateUp( T* A, Rank );
template <typename T>
    void heapify( T* A, Rank n );
template <typename T>

class PQVector : public PQ<T>, public Vector<T>
{
  public:
    PQVector() {}
    PQVector( T* E, int n ) { Vector<T>::copyFrom( E, 0, n ); heapify( Vector<T>::_elem, n); }
    void insert( T e ) { Vector<T>::insert( e ); percolateUp( Vector<T>::_elem, Vector<T>::_size - 1 );}
    T getMax() { return Vector<T>::_elem[0]; }
    T delMax() 
    {
      std::swap ( Vector<T>::_elem[0], Vector<T>::_elem[--Vector<T>::_size] ); 
      percolateDown( Vector<T>::_elem, Vector<T>::_size, 0 );
      return Vector<T>::_elem[Vector<T>::_size];
    }
  };

#include <boost/core/demangle.hpp>
template<typename T>
std::ostream& operator<< ( std::ostream& os, PQVector<T> H )
{
  int n = 1;
  os << boost::core::demangle( typeid(H).name() ) << "\tSize:\t" << H.size() << "\n{\n";
  for( Rank i = 0; i < H.size() ; i++ )
  {
    os << H[i] << "\t";
    if ( i == std::pow( 2, n ) - 2 )
    {
      ++n; std::cout<<'\n';
    }
  }
  os << "}\n" << std::endl;
  return os;}

#include "PQvector_imple.h"

#endif // !__PQ_VECTOR__
