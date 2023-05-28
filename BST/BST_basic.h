#ifndef __BST_BASIC__
#define __BST_BASIC__

#include <cstdlib>
#include <iostream>
template <typename T> BinNodePosi<T> &BST<T>::search(const T &e) {
  if (BST<T>::_root == nullptr || e == BST<T>::_root->data) {
    _s = nullptr;
    return BST<T>::_root;
  }
  for (_s = BST<T>::_root;;) {
    BinNodePosi<T> &n = (e < _s->data) ? _s->lc : _s->rc;
    if (n == nullptr || n->data == e)
      return n;
    _s = n;
    // return nullptr or nodeposi&  -->  a spot to insert....
  }
}

template <typename T> BinNodePosi<T> BST<T>::insert(const T &e) {
  BinNodePosi<T> &n = search(e);
  if (n != NULL)
    return n;
  n = new BinNode<T>(e, _s);
  ++BinTree<T>::_size;
  BinTree<T>::updateHeightAbove(n);
  return n;
}

template <typename T>
BinNodePosi<T> BST<T>::removeAt(BinNodePosi<T> &n, BinNodePosi<T> &s) {
  // n could be leaf, single child or double child.
  // need a var to store succ. data swap succ & n.
  BinNodePosi<T> temp = n;
  BinNodePosi<T> succ = nullptr;
  if (!HasLChild(n))
    succ = n = n->rc;
  else if (!HasRChild(n))
    succ = n = n->lc;
  else { // leaf
    if (rand() % 1) {
      temp = temp->succ();
      std::swap(temp->data, n->data);
      BinNodePosi<T> tempPrev = temp->parent; // now need to safe delete temp.
      if (tempPrev == n)
        tempPrev->rc = succ = temp->rc;
      else
        tempPrev->lc = succ = temp->rc;
    } else {
      temp = temp->prev();
      std::swap(temp->data, n->data);
      BinNodePosi<T> tempNext = temp->parent; // now need to safe delete temp.
      if (tempNext == n)
        tempNext->lc = succ = temp->lc;
      else
        tempNext->rc = succ = temp->lc;
    }
  }
  if (BST<T>::_root != temp)
    s = temp->parent;
  if (succ)
    succ->parent = s;
  BinTree<T>::updateHeightAbove(s);
  return succ;
}

template <typename T> bool BST<T>::remove(const T &e) {
  BinNodePosi<T> &n = search(e);
  if (!n)
    return false; // no target
  removeAt(n, _s);
  --BinTree<T>::_size;
  BinTree<T>::updateHeightAbove(_s);
  return true;
}
// template <typename T> BinNodePosi<T> BST<T>::connect34 (
//    BinNodePosi<T> a, BinNodePosi<T> b, BinNodePosi<T> c,
//    BinNodePosi<T> T0, BinNodePosi<T> T1, BinNodePosi<T> T2, BinNodePosi<T> T3
// ) {
//    /*DSA*///print(a); print(b); print(c); printf("\n");
//    a->lc = T0; if ( T0 ) T0->parent = a;
//    a->rc = T1; if ( T1 ) T1->parent = a; this->updateHeight ( a );
//    c->lc = T2; if ( T2 ) T2->parent = c;
//    c->rc = T3; if ( T3 ) T3->parent = c; this->updateHeight ( c );
//    b->lc = a; a->parent = b;
//    b->rc = c; c->parent = b; this->updateHeight ( b );
//    return b; //¸Ã×ÓÊ÷ÐÂµÄ¸ù½Úµã
// }
// template <typename T> BinNodePosi<T> BST<T>::rotateAt( BinNodePosi<T> v ) { //vÎª·Ç¿ÕËï±²½Úµã
//    /*DSA*/if ( !v ) { printf ( "\a\nFail to rotate a null node\n" ); exit ( -1 ); }
//    BinNodePosi<T> p = v->parent; BinNodePosi<T> g = p->parent; //ÊÓv¡¢pºÍgÏà¶ÔÎ»ÖÃ·ÖËÄÖÖÇé¿ö
//    if ( IsLChild( p ) ) // zig
//       if ( IsLChild( v ) ) { /* zig-zig */ /*DSA*/ // printf("\tzIg-zIg: ");
//          p->parent = g->parent; //ÏòÉÏÁª½Ó
//          return connect34( v, p, g, v->lc, v->rc, p->rc, g->rc );
//       } else { /* zig-zag */ /*DSA*/ // printf("\tzIg-zAg: ");
//          v->parent = g->parent; //ÏòÉÏÁª½Ó
//          return connect34( p, v, g, p->lc, v->lc, v->rc, g->rc );
//       }
//    else // zag
//       if ( IsRChild( v ) ) { /* zag-zag */ /*DSA*/ // printf("\tzAg-zAg: ");
//          p->parent = g->parent; //ÏòÉÏÁª½Ó
//          return connect34( g, p, v, g->lc, p->lc, v->lc, v->rc );
//       } else { /* zag-zig */  /*DSA*///printf("\tzAg-zIg: ");
//          v->parent = g->parent; //ÏòÉÏÁª½Ó
//          return connect34( g, v, p, g->lc, v->lc, v->rc, p->rc );
//       }
// }
template <typename T>
BinNodePosi<T> BST<T>::rotateGFS(BinNodePosi<T> a, BinNodePosi<T> b,
                                 BinNodePosi<T> c, BinNodePosi<T> t1,
                                 BinNodePosi<T> t2, BinNodePosi<T> t3,
                                 BinNodePosi<T> t4) {
  a->lc = t1; if (t1) t1->parent = a; 
  a->rc = t2; if (t2) t2->parent = a; BinTree<T>::updateHeight(a);
  c->lc = t3; if (t3) t3->parent = c;
  c->rc = t4; if (t4) t4->parent = c; BinTree<T>::updateHeight(c);
  b->lc = a; a->parent = b;
  b->rc = c; c->parent = b; BinTree<T>::updateHeight(b);
  return b;
}
//                   b
//            a            c
//      1          2     3        4

template <typename T> BinNodePosi<T> BST<T>::rotate(BinNodePosi<T> son) {
  if (son == nullptr) {
    std::cout << "error! Fail to rotate a null node/n";
    exit(-1);
  }
  BinNodePosi<T> fa = son->parent;
  BinNodePosi<T> gf = fa->parent;
  if (IsLChild(fa)) {
    if (IsLChild(son)) {
      fa->parent = gf->parent;
      return rotateGFS(son, fa, gf, son->lc, son->rc, fa->rc, gf->rc);
    } else {
      son->parent = gf->parent;
      return rotateGFS(fa, son, gf, fa->lc, son->lc, son->rc, gf->rc);
    }
  } else {
    if (IsLChild(son)) {
      son->parent = gf->parent;
      return rotateGFS(gf, son, fa, gf->lc, son->lc, son->rc, fa->rc);
    } else {
      fa->parent = gf->parent;
      return rotateGFS(gf, fa, son, gf->lc, fa->lc, son->lc, son->rc);
    }
  }
}

#endif // !__BST_BASIC_
