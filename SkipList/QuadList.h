/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-24 16:24:13
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-24 17:18:01
 */

#ifndef __QUADLIST__
#define __QUADLIST__
#include "QuadNode.h"
using Rank = unsigned int;

template <typename T> struct Quadlist {

protected:
  void init();
  int clear();

public:
  Rank _size;
  QNodePosi<T> header, trailer;
  Quadlist() { init(); }
  ~Quadlist() {
    clear();
    delete header;
    delete trailer;
  }
  QNodePosi<T> first() const { return header->next; }
  QNodePosi<T> last() const { return trailer->prev; }
  Rank size() const { return _size; }
  T remove(QNodePosi<T> p);
  QNodePosi<T> insert(T const &e, QNodePosi<T> p, QNodePosi<T> b = nullptr);
  void traverse(void (*)(T &));
  template <typename VST> void traverse(VST &);
}; // Quadlist

#endif // !__QUADLIST__
