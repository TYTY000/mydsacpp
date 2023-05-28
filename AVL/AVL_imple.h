#ifndef __AVL_IMPLE__
#define __AVL_IMPLE__

#define Balanced(X) (stature((X)->lc) == stature((X)->rc))
#define Baldiff(X) (stature((X)->lc) - stature((X)->rc))
#define ISBALANCE(X) ((Baldiff(X) < 2) && (Baldiff(X) > -2))

#define tallerChild(X)                                                         \
  (stature((X)->lc) > stature((X)->rc)   ? (X)->lc                             \
   : stature((X)->lc) < stature((X)->rc) ? (X)->rc                             \
   : IsLChild((X))                       ? (X)->lc                             \
                                         : (X)->rc)
// #define FromParentTo( x ) /*À´×Ô¸¸Ç×µÄÒýÓÃ*/ \
//    ( IsRoot(x) ? this->_root : ( IsLChild(x) ? (x)->parent->lc : (x)->parent->rc ) )
// template <typename T>
// BinNodePosi<T> AVL<T>::insert(const T &e) { // ½«¹Ø¼üÂëe²åÈëAVLÊ÷ÖÐ
//   BinNodePosi<T> &x = this->search(e);
//   if (x)
//     return x; // È·ÈÏÄ¿±ê½Úµã²»´æÔÚ
//   BinNodePosi<T> xx = x = new BinNode<T>(e, this->_s);
//   this->_size++; // ´´½¨ÐÂ½Úµãx
//   for (BinNodePosi<T> g = this->_s; g; g = g->parent)
//     if (!AvlBalanced(g)) {
//       FromParentTo(g) =
//           this->rotateAt(tallerChild(tallerChild(g))); // ÖØÐÂ½ÓÈëÔ­Ê÷
//       break; // ¾Ö²¿×ÓÊ÷¸´ºâºó£¬¸ß¶È±ØÈ»¸´Ô­£»Æä×æÏÈÒà±ØÈç´Ë£¬¹Êµ÷Õû½áÊø
//     } else
//       this->updateHeight(g);
//   return xx; // ·µ»ØÐÂ½ÚµãÎ»ÖÃ
// }

// template <typename T> bool AVL<T>::remove(const T &e) { // ´ÓAVLÊ÷ÖÐÉ¾³ý¹Ø¼üÂëe
//   BinNodePosi<T> &x = this->search(e);
//   if (!x)
//     return false; // È·ÈÏÄ¿±ê´æÔÚ£¨ÁôÒâthis->_sµÄÉèÖÃ£©
//   BST<T>::removeAt(x, this->_s);
//   this->_size--; // ÏÈ°´BST¹æÔòÉ¾³ýÖ®£¨´Ëºó£¬Ô­½ÚµãÖ®¸¸this->_s¼°Æä×æÏÈ¾ù¿ÉÄÜÊ§ºâ£©
//   for (BinNodePosi<T> g = this->_s; g; g = g->parent) {
//     if (!AvlBalanced(g))
//       g = FromParentTo(g) = this->rotateAt(tallerChild(tallerChild(g)));
//     this->updateHeight(g);
//   } // ¿ÉÄÜÐè×öOmega(logn)´Îµ÷Õû¡ª¡ªÎÞÂÛÊÇ·ñ×ö¹ýµ÷Õû£¬È«Ê÷¸ß¶È¾ù¿ÉÄÜ½µµÍ
//   return true; // É¾³ý³É¹¦
// }

 template <typename T> BinNodePosi<T> AVL<T>::insert(const T &e) {
   BinNodePosi<T> &n = BST<T>::search(e);
   if (n != NULL)
     return n;
   BinNodePosi<T> t = n = new BinNode<T>(e, BST<T>::_s);
   BST<T>::_size++;
   for (BinNodePosi<T> fa = BST<T>::_s; fa; fa = fa->parent) {
     if (!ISBALANCE(fa)) {
       // trace(fa) = BST<T>::rotate(tallerChild(tallerChild(fa)));
       auto ptr = BST<T>::rotateAt(tallerChild(tallerChild(fa)));
       if ((fa->parent)&& (fa->data > ptr->data) )
         trace(fa) = ptr;
       if (this->_root->parent!=nullptr)
         this->_root = this->_root->parent;
       break;
     } else
       BST<T>::updateHeight(fa);
   }
   return t;
 }

template <typename T> bool AVL<T>::remove(const T &e) {
  BinNodePosi<T> &n = BST<T>::search(e);
  if (!n)
    return false;
  BST<T>::removeAt(n, (BST<T>::_s));
  BST<T>::_size--;
  for (BinNodePosi<T> fa = BST<T>::_s; fa; fa = fa->parent) {
    if (!ISBALANCE(fa)) {
      fa = trace(fa) = BST<T>::rotateAt(tallerChild(tallerChild(fa)));
    }
    BST<T>::updateHeight(fa);
  }
  return true;
}

#endif // !__AVL_IMPLE__
