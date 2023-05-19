#include "BTree.h"
#include "BNode.h"

// a little complex, we need to check whether n has more child than half=_m or
// not.....
template <typename T> void BTree<T>::underflow(BNodePosi<T> n) {
  while (n->child.size() < ((_m + 1) >> 1)) {
    BNodePosi<T> p = n->parent;
    if (p == NULL) { // root need not to be enough
      if (!n->key.size() &&
          n->child[0] != nullptr) // n left only a *, p is completely useless
      {
        // let the only child of n be root
        _root = n->child[0];
        _root->parent = nullptr;
        n->child[0] = nullptr;
        delete n;
      }
      return;
    }
    Rank r = 0;
    while (p->child[r] != n)
      r++; // n is the r th child of p
    // now we need to deal with the easy case --> this node has more than
    // half-_m
    if (r > 0) {
      BNodePosi<T> L = p->child[r - 1];
      // when L has enough, give a right-most key to p, p then instead give a
      // key to n and give a right-most child
      if (L->child.size() > ((_m + 1) >> 1)) {
        n->key.insert(0, p->key[r - 1]);
        p->key[r - 1] = L->key.remove(L->key.size() - 1);
        n->child.insert(0, L->child.remove(L->child.size() - 1));
        // don't forget to bind this child
        if (n->child[0] != nullptr)
          n->child[0]->parent = n;
        return;
      }
    }
    // present situation is no L or L is not enough,need to do same to L
    if (r < p->child.size() - 1) {
      BNodePosi<T> R = p->child[r + 1];
      // when R has enough, give a left-most key to p, p then instead give a key
      // to n and give a left-most child
      if (R->child.size() > ((_m + 1) >> 1)) {
        n->key.insert(n->key.size(), p->key[r]); // misspell cost me two hour
        p->key[r] = R->key.remove(0);
        n->child.insert(n->child.size(), R->child.remove(0));
        // don't forget to bind this child
        if (n->child[n->child.size() - 1] != nullptr)
          n->child[n->child.size() - 1]->parent = n;
        return;
      }
    }
    // L & R both not enough, or nullptr.
    // could give p to L | R
    if (r > 0) {
      BNodePosi<T> L = p->child[r - 1];
      L->key.insert(L->key.size(), p->key.remove(r - 1));
      p->child.remove(r);
      L->child.insert(L->child.size(), n->child.remove(0));
      if (L->child[L->child.size() - 1] != nullptr)
        L->child[L->child.size() - 1]->parent = L;
      while (!n->key.empty()) {
        L->key.insert(L->key.size(), n->key.remove(0));
        L->child.insert(L->child.size(), L->child.remove(0));
        if (L->child[L->child.size() - 1] != nullptr)
          L->child[L->child.size() - 1]->parent = L;
      }
      delete n;
    } else {
      BNodePosi<T> R = p->child[r + 1];
      R->key.insert(0, p->key.remove(r));
      p->child.remove(r);
      R->child.insert(0, n->child.remove(n->child.size() - 1));
      if (R->child[0] != nullptr)
        R->child[0]->parent = R;
      while (!n->key.empty()) {
        R->key.insert(0, n->key.remove(n->key.size() - 1));
        R->child.insert(0, n->child.remove(n->child.size() - 1));
        if (R->child[0] != nullptr)
          R->child[0]->parent = R;
      }
      delete n;
    }
    n = p;
  }
}

template <typename T> void BTree<T>::overflow(BNodePosi<T> n) {
  // _m = key.size() = child.size()-1
  while (_m <= n->key.size()) {
    Rank i = _m / 2;
    BNodePosi<T> s = new BNode<T>();
    for (Rank j = 0; j < _m - i - 1; j++) {
      s->child.insert(j, n->child.remove(i + 1));
      s->key.insert(j, n->key.remove(i + 1));
    }
    s->child[_m - i - 1] = n->child.remove(i + 1);
    if (s->child[0])
      for (Rank j = 0; j < _m - i; j++)
        s->child[j]->parent = s;
    BNodePosi<T> p = n->parent;
    if (p == nullptr) {
      _root = p = new BNode<T>();
      p->child[0] = n;
      n->parent = p;
    }
    Rank r = p->key.search(n->key[0]) + 1; // need to be bigger than search....
    p->key.insert(r, n->key.remove(i));
    p->child.insert(r + 1, s);
    s->parent = p;
    n = p;
  }
}

template <typename T> BNodePosi<T> BTree<T>::search(const T &e) {
  BNodePosi<T> n = _root;
  _last = nullptr;
  while (n != nullptr) {
    int r = n->key.search(e);
    if ((r >= 0) && (n->key[r] == e))
      return n;
    _last = n;
    n = n->child[r + 1];
  }
  return nullptr;
}

template <typename T> bool BTree<T>::insert(const T &e) {
  BNodePosi<T> n = BTree<T>::search(e);
  if (n != nullptr)
    return false;
  // _last is the spot (parent) of the insertion
  int r = _last->key.search(e);
  _last->key.insert(r + 1, e);
  _last->child.insert(r + 2, nullptr);
  _size++;
  // in case _last is full
  overflow(_last);
  return true;
}

template <typename T> bool BTree<T>::remove(const T &e) {
  BNodePosi<T> n = BTree<T>::search(e);
  if (n == nullptr)
    return false;
  // if not leaf, goto succ leaf.
  int r = n->key.search(e);
  // and swap to leaf.
  if (n->child[0]) {
    BNodePosi<T> s = n->child[r + 1];
    while (s->child[0] != nullptr)
      s = s->child[0];
    n->key[r] = s->key[0];
    n = s;
    r = 0;
  }
  // now need to remove n->key[r] and n->child[r+1]
  n->key.remove(r);
  n->child.remove(r + 1);
  _size--;
  // in case n is not enough
  underflow(n);
  return true;
}
