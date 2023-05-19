/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-18 17:32:49
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-19 16:10:08
 */

#ifndef __BNODE__
#define __BNODE__

#include "../vector/vector.h"
template <typename T> struct BNode;
template <typename T> using BNodePosi = BNode<T> *;

template <typename T> struct BNode {
public:
  BNodePosi<T> parent;
  Vector<T> key;
  Vector<BNodePosi<T>> child;
  // due to unknown vector size, no further interface on BNode.
  BNode() {
    parent = nullptr;
    key = child.insert(nullptr);
  }
  BNode(T e, BNodePosi<T> lc = nullptr, BNodePosi<T> rc = nullptr) {
    parent = nullptr;
    key.insert(0, e);
    child.insert(lc);
    child.insert(rc);
    if (lc != nullptr)
      lc->parent = this;
    if (rc != nullptr)
      rc->parent = this;
  }
};

#endif // !__BNODE__
