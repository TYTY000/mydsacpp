/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-15 11:55:10
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-15 21:16:34
 */

#ifndef __STACK_VEC__
#define __STACK_VEC__

#include "../vector/vector.h"
#include <iostream>

template <typename T>
class Stack: public Vector<T> {
  public:
    void push( const T& e ) { Vector<T>::insert( e ); }
    T pop() { return Vector<T>::remove( Vector<T>::size() - 1 ); }
    T& peek() const { return ( *this )[Vector<T>::size() - 1]; }
    void reverse(){
      auto t = Vector<T>::_elem[0];  auto b = Vector<T>::_elem[Vector<T>::_size - 1];
      while ( t - b > 0 ) std::swap( t, b );
    }
};
#include <boost/core/demangle.hpp>
template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& S)
{
  os << boost::core::demangle( typeid(S).name() ) << "\tSize:\t" << S.size() << "\n{\n";
  for( Rank i = 0; i < S.size() ; i++ )
  {
    os << S[i] << "\t";
    if ((++i) % 10 == 0)
    os << "\n";
  }
  os << "}" << std::endl;
  return os;
}

#endif // !__STACK_VEC__
