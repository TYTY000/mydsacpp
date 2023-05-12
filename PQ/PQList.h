/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-11 18:27:43
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-11 18:31:30
 */

#ifndef __PQLIST__
#define __PQLIST__

#include "../list/list.h"
#include "../PQ/PQ.h"

template <typename T>
class PQList : public PQ<T>, public List<T>{
  public:
    PQList() {}
    PQList( T* E, int n ) { while ( n-- > 0 ) List<T>::insertAsLast( E[n] ); }
    void insert( T e ) { List<T>::insertAsLast( e ); }
    T getMax() { return List<T>::takeMax()->data; }
    T delMax() { return List<T>::remove( List<T>::takeMax() ); }
};

#endif // !__PQLIST__
