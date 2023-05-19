/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-18 21:05:18
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-19 16:26:29
 */

#ifndef __BTREE__
#define __BTREE__

#include "BNode.h"
using Rank = unsigned int;

template <typename T> class BTree {
protected:
  Rank _size;
  Rank _m;
  BNodePosi<T> _root;
  BNodePosi<T> _last;
  void underflow(BNodePosi<T>);
  void overflow(BNodePosi<T>);

public:
  BTree(int m = 3) : _size(0), _m(m) {
  _root = new BNode<T>();
}
  ~BTree(){
  if (_root)
    delete _root;
}
  BTree(BTree<T> &&) = delete;
  BTree(const BTree<T> &) = delete;
  BTree &operator=(BTree<T> &&) = delete;
  BTree &operator=(const BTree<T> &) = delete;
  Rank size() { return _size; }
  const Rank m() { return _m; }
  BNodePosi<T>& root() { return _root; }
  bool empty() const { return !_root; }
  BNodePosi<T> search(const T &);
  bool insert(const T &);
  bool remove(const T &);
};

#endif // !__BTREE__
