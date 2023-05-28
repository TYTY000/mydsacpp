/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-19 17:51:05
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-27 23:01:31
 */


#ifndef __RBTREE__
#define __RBTREE__

#define DSA_RBTREE 1
#include "../BST/BST.h"

template <typename T> class RBTree : public BST<T> {
public:
  bool remove(const T &);
  BinNodePosi<T> insert(const T &);

protected:
  BinNodePosi<T> removeAt(BinNodePosi<T> &, BinNodePosi<T> &);
  Rank updateHeight(BinNodePosi<T>);
  void solveRR(BinNodePosi<T>);
  void solveBB(BinNodePosi<T>);
};

#define IsBlack(X) (!(X) || ((X)->color == RB_BLACK))
#define IsRed(X) (!IsBlack(X))
#define BlackHeightUpdated(X)                                                  \
  ((stature((X)->lc) == stature((X)->rc)) &&                                   \
   ((X)->height == (IsRed(X) ? stature((X)->lc) : stature((X)->lc) + 1)))

#include "RBTree_imple.h"
#endif // !__RBTREE__
