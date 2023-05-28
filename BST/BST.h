#ifndef __BST__
#define __BST__

#include "../binTree/binTree.h"

template <typename T> class BST : public BinTree<T> {
public:
  virtual BinNodePosi<T> &search(const T &e);
  virtual BinNodePosi<T> insert(const T &e);
  virtual bool remove(const T &e);
  virtual BinNodePosi<T> removeAt(BinNodePosi<T> &, BinNodePosi<T> &);

protected:
  // BinNodePosi<T> connect34( // °´ÕÕ¡°3 + 4¡±½á¹¹£¬Áª½Ó3¸ö½Úµã¼°ËÄ¿Ã×ÓÊ÷
  //     BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>,
  //     BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>);
  // BinNodePosi<T> rotateAt(BinNodePosi<T> x); // ¶Ôx¼°Æä¸¸Ç×¡¢×æ¸¸×öÍ³Ò»Ðý×ªµ÷Õû
  BinNodePosi<T> rotate(BinNodePosi<T>);
  BinNodePosi<T> rotateGFS(BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>,
                           BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>,
                           BinNodePosi<T>);
  BinNodePosi<T> _s; //  approx target
};

#include "BST_imple.h"

#endif // !__BST__
