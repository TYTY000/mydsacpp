/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-20 16:58:41
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-27 23:11:46
 */

#ifndef __RBTREE_INSERT_H__
#define __RBTREE_INSERT_H__

template <typename T> BinNodePosi<T> RBTree<T>::insert(const T &e) {
  BinNodePosi<T> &s = BST<T>::search(e);
  if ((this->_size !=0)&&(s != nullptr))
    return s;
  s = new BinNode<T>(e, this->_s, nullptr, nullptr, 0);
  BST<T>::_size++;
  BinNodePosi<T> oldS = s;
  solveRR(s);
  return oldS;
}

#endif // !__RBTREE_INSERT_H__
