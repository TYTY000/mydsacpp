/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-18 09:31:32
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-18 13:33:26
 */

#ifndef __SPLAY_IMPLE__
#define __SPLAY_IMPLE__
#include "./splayTree.h"
#include <cassert>

template <typename BNP> static inline void attachAsLChild(BNP p, BNP lc) {
  p->lc = lc;
  if (lc)
    lc->parent = p;
}

template <typename BNP> static inline void attachAsRChild(BNP p, BNP rc) {
  p->lc = rc;
  if (rc)
    rc->parent = p;
}

template <typename T> BinNodePosi<T> SplayTree<T>::splay(BinNodePosi<T> s) {
  if (s == nullptr)
    return nullptr;
  BinNodePosi<T> f;
  BinNodePosi<T> g;
  while ((f = s->parent) && (g = f->parent)) {
    BinNodePosi<T> gf = g->parent;
    if (IsLChild(s)) {
      if (IsLChild(f)) {
        attachAsLChild(f, s->rc);
        attachAsLChild(g, f->rc);
        attachAsRChild(s, f);
        attachAsRChild(f, g);
      } else {
        attachAsRChild(g, s->lc);
        attachAsLChild(f, s->rc);
        attachAsLChild(s, g);
        attachAsRChild(s, f);
      }
    } else if (IsRChild(f)) {
      attachAsRChild(g, f->lc);
      attachAsRChild(f, s->rc);
      attachAsLChild(s, f);
      attachAsLChild(f, g);
    } else {
      attachAsRChild(f, s->lc);
      attachAsLChild(g, s->rc);
      attachAsLChild(s, f);
      attachAsRChild(s, g);
    }
    if (!gf)
      s->parent = nullptr;
    else if (g == gf->lc)
      attachAsLChild(gf, s);
    else
      attachAsRChild(gf, s);
    BinTree<T>::updateHeight(g);
    BinTree<T>::updateHeight(f);
    BinTree<T>::updateHeight(s);
  }
  if ((f = s->parent)) {
    if (IsLChild(s)) {
      attachAsLChild(f, s->rc);
      attachAsRChild(s, f);
    } else {
      attachAsRChild(f, s->lc);
      attachAsLChild(s, f);
    }
    BinTree<T>::updateHeight(f);
    BinTree<T>::updateHeight(s);
  }
  s->parent = nullptr;
  return s;
}

template <typename T> BinNodePosi<T> &SplayTree<T>::search(const T &e) {
  if (BST<T>::size() != 0) {
    BinNodePosi<T> n = BST<T>::search(e);
    BinTree<T>::_root = splay(n ? n : BST<T>::_s);
  }
  return BinTree<T>::_root;
}

template <typename T> BinNodePosi<T> SplayTree<T>::insert(const T &e) {
  if (!BST<T>::_root) {
    BST<T>::_size++;
    return BST<T>::_root = new BinNode<T>(e);
  }                         // null tree
  if (search(e)->data == e) // match
    return BST<T>::_root;
  // ready to insert
  BST<T>::_size++;
  BinNodePosi<T> n = BST<T>::_root;
  // less lc bigger rc
  if (*BST<T>::_root < e) { // bigger
    n->parent = BST<T>::_root = new BinNode<T>(e, nullptr, n, n->rc);
    if (HasRChild(n)) {
      n->rc->parent = BST<T>::_root;
      n->rc = nullptr;
    }
  } else { // less
    n->parent = BST<T>::_root = new BinNode<T>(e, nullptr, n->lc, n);
    if (HasLChild(n)) {
      n->lc->parent = BST<T>::_root;
      n->lc = nullptr;
    }
  }
  this->updateHeightAbove(n);
  return BST<T>::_root;
}

template <typename T> bool SplayTree<T>::remove(const T &e) {
  if (!BST<T>::_root || (e != search(e)->data)) {
    return false;
  }
  BinNodePosi<T> n = BST<T>::_root;
  BinNodePosi<T> L = BST<T>::_root->lc;
  BinNodePosi<T> R = BST<T>::_root->rc;
  delete n;
  if (!L) {
    BST<T>::_root = R;
    if (BST<T>::_root)
      BST<T>::_root->parent = nullptr;
  } else if (!R) {
    BST<T>::_root = L;
    if (BST<T>::_root)
      BST<T>::_root->parent = nullptr;
  } else {

    if (rand() % 2) {
      L->parent = nullptr;
      BST<T>::_root->lc = nullptr;
      BST<T>::_root = BST<T>::_root->rc;
      BST<T>::_root->parent = nullptr;
      BST<T>::search(e);
      // _root->lc = nullptr
      BST<T>::_root->lc = L;
      L->parent = BST<T>::_root;
    } else {
      R->parent = nullptr;
      BST<T>::_root->rc = nullptr;
      BST<T>::_root = BST<T>::_root->lc;
      BST<T>::_root->parent = nullptr;
      BST<T>::search(e);
      // _root->rc = nullptr
      BST<T>::_root->rc = R;
      R->parent = BST<T>::_root;
    }
  }
  BST<T>::_size--;
  if (BST<T>::_root)
    BinTree<T>::updateHeight(BST<T>::_root);
  return true;
}
#endif // !__SPLAY_IMPLE__
