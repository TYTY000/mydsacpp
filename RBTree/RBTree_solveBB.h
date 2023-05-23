/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-20 16:59:36
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-21 19:26:55
 */

#ifndef __RBTREE_BB_H__
#define __RBTREE_BB_H__

template <typename T> void RBTree<T>::solveBB(BinNodePosi<T> n)
{
  // ensure p is not nullptr;
  BinNodePosi<T> f = n? n: this->BST<T>::_s; if(f == nullptr) return;
  BinNodePosi<T> s = sibling(n);
  if(IsBlack(s)){
    BinNodePosi<T> tmpR = nullptr;
    if(IsRed(s->lc)) tmpR = s->rc;
    if(IsRed(s->rc)) tmpR = s->lc;
    if(tmpR!=nullptr){ // sib has red child.
      RBColor old = f->color;
      BinNodePosi<T> tmp = trace(f) = BST<T>::rotate(tmpR);
      if(HasLChild(tmp)) {tmp->lc->color = RB_BLACK; updateHeight(tmp->lc);}
      if(HasRChild(tmp)) {tmp->rc->color = RB_BLACK; updateHeight(tmp->rc);}
      tmp->color = old; updateHeight(tmp);
    } else { // slbling has no red child.
      f->color = RB_RED;f->height--; // make sibling red.
      if(IsRed(f)){
        f->color = RB_BLACK;
      } else { // p is black, too.  update p's blackheight, and recurse up to root.
        f->height--;
        solveBB(f);
      }
    }
  } else { // sibling is red. nephew is black.
    // make sibling black. father red.
    s->color =RB_BLACK;f->color = RB_RED;
    BinNodePosi<T> tmp = IsRChild(s)? s->rc: s->lc;
    this->BST<T>::_s = f; trace(f)=BST<T>::rotate(tmp);
    solveBB(n);
  }
}

#endif // !__RBTREE_REMOVE_H__
