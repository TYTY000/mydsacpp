/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-15 11:55:10
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-15 21:01:04
 */

#ifndef __stack_list__
#define __stack_list__

#include "../list/list.h"
#include <iostream>

template <typename T>
class Stack: public List<T> {
  public:
    void push( const T& e ) 
    { 
      List<T>::insertAsLast( e ); 
    }
    T pop() 
    { 
      return List<T>::remove( List<T>::last() ); 
    }
    T& peek() const { return List<T>::last()->data; }
    void reverse(){
      auto t = List<T>::first(); auto b = List<T>::last();
      std::swap( t->data, b->data );
      t = t->next; b = b->prev;
    }
};
#include <boost/core/demangle.hpp>
template <typename T>
std::ostream& operator<<(std::ostream& ostr, const Stack<T>& L)
{
  int count = 0;
  ostr << boost::core::demangle( typeid(L).name() ) << "\tSize:\t" << L.size() << "\n{\n";
  for( ListNodePosi<T> p = L.first(); count < L.size() ; p = p->next )
  {
    if ( !p->data )break;
    ostr << p->data << "\t";
    if ((++count) % 10 == 0)
    ostr << "\n";
  }
  ostr << "}" << std::endl;
  return ostr;
}
#endif // !__stack_list__
