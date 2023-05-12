#ifndef __listNode__
#define __listNode__
#include <cstddef>
#include <memory>

template <typename T> struct ListNode;
using Rank = unsigned int;
template <typename T> using ListNodePosi = ListNode<T>*;
//#define ListNodePosi<T> ListNode<T>*

template <typename T>
struct ListNode
{
  T data; ListNodePosi<T> prev; ListNodePosi<T> next;
  ListNode() : data(), prev(nullptr), next(nullptr){}
  ListNode( T e ) : data(e), prev(nullptr), next(nullptr) {} 
  ListNode( T e, ListNodePosi<T> p, ListNodePosi<T> n ):
    data(e), prev(p), next(n) {}
  ListNodePosi<T> insertAsPrev( const T& e );
  ListNodePosi<T> insertAsNext( const T& e );
};

#include "listNode_imple.h"

#endif // !_listNode_

