/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-18 09:26:58
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-18 12:45:28
 */

#ifndef __SPLAY_TREE__
#define __SPLAY_TREE__

#include "../BST/BST.h"

template <typename T> class SplayTree : public BST<T> {
protected:
  BinNodePosi<T> splay(BinNodePosi<T> n);

public:
  BinNodePosi<T> &search(const T &e);
  BinNodePosi<T> insert(const T &e);
  bool remove(const T &e);
};

#endif // !__SPLAY_TREE__
