#ifndef __BINNODE_IMPLE__
#define __BINNODE_IMPLE__

#define IsRoot(X) (!((X)->parent))
#define IsParent(X) (!IsRoot(X))
#define IsLChild(X) (!IsRoot(X) && ((X) == (X)->parent->lc))
#define IsRChild(X) (!IsRoot(X) && ((X) == (X)->parent->rc))
#define HasLChild(X) ((X)->lc)
#define HasRChild(X) ((X)->rc)
#define HasChild(X) (HasRChild(X) || HasLChild(X))
#define HasBChild(X) (HasLChild(X) && HasRChild(X))
#define IsLeaf(X) (!HasChild(X))
#define sibling(X) (IsLChild(X) ? (X)->parent->rc : (X)->parent->lc)
#define trace(X)                                                               \
  (IsRoot(X) ? BinTree<T>::_root                                               \
             : (IsLChild(X) ? (X)->parent->lc : (X)->parent->rc))
#define uncle(X) (sibling((X)->parent))

template <typename T> Rank BinNode<T>::size() {
  Rank s = 1;
  if (lc)
    s += lc->size();
  if (rc)
    s += rc->size();
  return s;
}

template <typename T> BinNodePosi<T> BinNode<T>::insertAsLC(const T &e) {
  return lc = new BinNode(e, this);
}

template <typename T> BinNodePosi<T> BinNode<T>::insertAsRC(const T &e) {
  return rc = new BinNode(e, this);
}

#include "binNode_succ.h"
#include "binNode_trav.h"

#endif
