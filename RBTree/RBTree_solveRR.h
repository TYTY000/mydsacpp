/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-21 16:07:17
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-21 19:26:33
 */

template <typename T> void RBTree<T>::solveRR(BinNodePosi<T> n) {
  if (IsRoot(n)) {
    BST<T>::_root->color = RB_BLACK;
    BST<T>::_root->height++;
    return;
  }
  BinNodePosi<T> f = n->parent;
  if (IsBlack(f))
    return;
  // n && f RED
  BinNodePosi<T> g = f->parent; // g BLACK
  BinNodePosi<T> u = uncle(n);
  if (IsBlack(u)) {
    if (IsRChild(n) == IsRChild(f))
      f->color = RB_BLACK;
    else
      n->color = RB_BLACK;
    g->color = RB_RED;
    BinNodePosi<T> gf = g->parent;
    BinNodePosi<T> s = trace(g) = BST<T>::rotate(n);
    s->parent = gf;
  } else { // just make father & uncle be red && height +1
    f->color = RB_BLACK;
    f->height++;
    u->color = RB_BLACK;
    u->height++;
    g->color = RB_RED;
    solveRR(g);
  }
}
