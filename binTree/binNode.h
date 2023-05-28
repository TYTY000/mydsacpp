#ifndef __BINNODE__
#define __BINNODE__

template <typename T> struct BinNode;
template <typename T> using BinNodePosi = BinNode<T> *;
#if defined(DSA_RBTREE)
#define stature(p) ((p) ? (p)->height : 0)
#endif // DEBUG
#define stature(p) ((int)((p) ? (p)->height : -1))
using Rank = unsigned int;
typedef enum { RB_RED, RB_BLACK } RBColor;

template <typename T> struct BinNode {
  T data;
  BinNodePosi<T> parent;
  BinNodePosi<T> lc;
  BinNodePosi<T> rc;
  Rank height;
  Rank npl;
  RBColor color;
  BinNode()
      : parent(nullptr), lc(nullptr), rc(nullptr), height(0), npl(1),
        color(RB_RED) {}
  BinNode(T e, BinNodePosi<T> p = nullptr, BinNodePosi<T> l = nullptr,
          BinNodePosi<T> r = nullptr, Rank h = 0, Rank n = 1,
          RBColor c = RB_RED)
      : data(e), parent(p), lc(l), rc(r), height(h), npl(n), color(c) {}

  Rank size();
  BinNodePosi<T> insertAsLC(const T &);
  BinNodePosi<T> insertAsRC(const T &);
  BinNodePosi<T> prev();
  BinNodePosi<T> succ();

  BinNodePosi<T> zig();
  BinNodePosi<T> zag();
  bool operator<(const BinNode &n) { return data < n.data; }
  bool operator==(const BinNode &n) { return data == n.data; }

  template <typename VST> void travLv(VST &);
  template <typename VST> void travPre(VST &);
  template <typename VST> void travMi(VST &);
  template <typename VST> void travPo(VST &);
};

#include "binNode_imple.h"

template <typename T> BinNodePosi<T> BinNode<T>::zig() {
   BinNodePosi<T> lChild = lc;
   lChild->parent = this->parent;
   if ( lChild->parent )
      ( ( this == lChild->parent->rc ) ? lChild->parent->rc : lChild->parent->lc ) = lChild;
   lc = lChild->rc; if ( lc ) lc->parent = this;
   lChild->rc = this; this->parent = lChild;
   height = 1 + std::max ( stature ( lc ), stature ( rc ) );
   lChild->height = 1 + std::max ( stature ( lChild->lc ), stature ( lChild->rc ) );
   for ( BinNodePosi<T> x = lChild->parent; x; x = x->parent )
      if ( x->height == 1 + std::max(stature(x->lc), stature(x->rc))) 
         break;
      else
         x->height = 1 + std::max ( stature ( x->lc ), stature ( x->rc ) );
   return lChild;
}

template <typename T> BinNodePosi<T> BinNode<T>::zag() {
   BinNodePosi<T> rChild = rc;
   rChild->parent = this->parent;
   if ( rChild->parent )
      ( ( this == rChild->parent->lc ) ? rChild->parent->lc : rChild->parent->rc ) = rChild;
   rc = rChild->lc; if ( rc ) rc->parent = this;
   rChild->lc = this; this->parent = rChild;
// update heights
   height = 1 + std::max ( stature ( lc ), stature ( rc ) );
   rChild->height = 1 + std::max ( stature ( rChild->lc ), stature ( rChild->rc ) );
   for ( BinNodePosi<T> x = rChild->parent; x; x = x->parent )
      if ( x->height == 1 + std::max(stature(x->lc), stature(x->rc))) 
         break;
      else
         x->height = 1 + std::max ( stature ( x->lc ), stature ( x->rc ) );
   return rChild;
}
#endif // !__BINNODE__
