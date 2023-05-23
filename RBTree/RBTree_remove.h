/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-20 16:56:43
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-21 19:29:20
 */

#ifndef __RBTREE_REMOVE_H__
#define __RBTREE_REMOVE_H__

#include <tuple>
template <typename T> bool RBTree<T>::remove(const T &e) {
  BinNodePosi<T> &s = BST<T>::search(e);
  if (s == nullptr)
    return false;
  BinNodePosi<T> r = removeAt(s, this->BST<T>::_s);
  if (BST<T>::_size == 0)
    return true;
  // regression: only root.
  if (this->BST<T>::_s== nullptr) {
    BST<T>::_root->color = RB_BLACK;
    updateHeight(BST<T>::_root);
    return true;
  }
  if (BlackHeightUpdated(this->BST<T>::_s))
    return true;
  // this case is when double black occurs,
  // if r is leaf.
  if (IsRed(r)) {
    r->color = RB_BLACK;
    r->height++;
    return true;
  }
  // r is not leaf, need to recurse up .
  solveBB(r);
  return true;
}

template <typename T>
BinNodePosi<T> RBTree<T>::removeAt(BinNodePosi<T> &s, BinNodePosi<T> &_s) {
  // need to find succ of s,
  BinNodePosi<T> succ = nullptr;
  BinNodePosi<T> tmp = s;
  if (!HasLChild(s))
    succ = s = s->rc;
  else if (!HasRChild(s))
    succ = s = s->lc;
  else {
    // Has both children
    tmp = s;
    tmp = tmp->succ();
    std::swap(tmp->data, s->data);
    BinNodePosi<T> n = tmp->parent;
    ((n == s) ? n->rc : n->lc) = succ = tmp->rc;
  }
  // now need to delete tmp
  this->BST<T>::_s = tmp->parent;
  if (succ != nullptr)
    succ->parent = this->BST<T>::_s;
  delete tmp;
  return succ;
}

#endif // !__RBTREE_REMOVE_H__
