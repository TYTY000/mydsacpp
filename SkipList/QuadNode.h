/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-24 16:21:39
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-24 17:10:48
 */

#ifndef __QUADNODE__
#define __QUADNODE__
#include "Entry.h"
template <typename T> struct QNode;
template <typename T> using QNodePosi = QNode<T> *;
template <typename T> struct QNode {
  T entry;
  QNodePosi<T> prev, next, above, below;
  QNode(T e = T(), QNodePosi<T> p = nullptr, QNodePosi<T> s = nullptr,
        QNodePosi<T> a = nullptr, QNodePosi<T> b = nullptr)
      : entry(e), prev(p), next(s), above(a), below(b) {}
  QNodePosi<T> insert(T const &e, QNodePosi<T> b = nullptr) {
    QNodePosi<T> x = new QNode<T>(e, this, next, nullptr, b);
    next->prev = x;
    next = x;
    if (b)
      b->above = x;
    return x;
  }
};

#endif
