/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-14 23:33:42
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-15 11:34:25
 */

#include <iostream>

// LeftHeap belongs to BinTree, and satisfy following property:
//            1.npl descending;
//            2.npl( lc(x) ) >= npl( rc(x) );
//            3.npl(x) = length(x.right);
//
// how to merge 2 heaps maintaining LeftHeap?
// 1.merge A_R with B, B_R to A_R;
// 2.if A_L and A_R violate rule 2, swap;
// 3. update npl of A;
  template <typename T>
static BinNodePosi<T> merge( BinNodePosi<T> n1, BinNodePosi<T> n2 )
{
  if ( n1 == nullptr ) return n2;
  if ( n2 == nullptr ) return n1;
  if ( lt( n1->data, n2->data ) ) std::swap( n1, n2 );
  n1->rc = merge( n1->rc, n2 );
  n1->rc->parent = n1;
  if ( n1->lc == nullptr || n1->lc->npl < n1->rc->npl )
    std::swap( n1->lc, n1->rc );
  n1->npl = ( n1->rc == nullptr ) ? n1->rc->npl + 1 : 1;
  return n1;
}

template <typename T>
void PQ_LeftHeap<T>::getMax ()
{
  return BinTree<T>::_root->data;
}


template <typename T>
void PQ_LeftHeap<T>::insert ( T e )
{
  BinNodePosi<T> n = new BinNode<T> ( e );
  BinTree<T>::_root = merge( n, BinTree<T>::_root );
  BinTree<T>::_root->parent = nullptr;
  _size++;
}

template <typename T>
T PQ_LeftHeap<T>::delMax()
{
  BinNodePosi<T> l = BinTree<T>::_root->lc;
  BinNodePosi<T> r = BinTree<T>::_root->rc;
  T n = BinTree<T>::_root->data;
  delete BinTree<T>::_root; size--;
  BinTree<T>::_root = merge ( l, r );
  if ( BinTree<T>::_root != nullptr ) BinTree<T>::_root->parent = nullptr;
  return n;
}
