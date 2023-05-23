#ifndef __AVL_IMPLE__
#define __AVL_IMPLE__

#define BALANCED(X) (stature((X).lc) == stature((X).rc))
#define BALDIFF(X) (stature((X).lc) - stature((X).rc))
#define ISBALANCE(X) ((BALDIFF(X) < 2) && (BALDIFF(X) > -2))

#define tallerChild(X)                                                         \
  (stature((X)->lc) > stature((X)->rc)   ? (X)->lc                             \
   : stature((X)->lc) < stature((X)->rc) ? (X)->rc                             \
   : IsLChild(*(X))                      ? (X)->lc                             \
                                         : (X)->rc)

template <typename T> BinNodePosi<T> AVL<T>::insert(const T &e) {
  BinNodePosi<T> &n = BST<T>::search(e);
  if (n != NULL)
    return n;
  BinNodePosi<T> t = n = new BinNode<T>(e, BST<T>::_s);
  BST<T>::_size++;
  for (BinNodePosi<T> fa = BST<T>::_s; fa; fa = fa->parent) {
    if (!ISBALANCE(*fa)) {
      trace(*fa) = BST<T>::rotate(tallerChild(tallerChild(fa)));
      break;
    } else
      BST<T>::updateHeight(fa);
  }
  return t;
}
TODO: remove algo incomplete.
// template <typename T> bool AVL<T>::remove(const T &e) {
//   BinNodePosi<T> &n = BST<T>::search(e);
//   if (!n)
//     return false;
//   BST<T>::removeAt(n, (BST<T>::_s));
//   BST<T>::_size--;
//   for (BinNodePosi<T> fa = BST<T>::_s; fa; fa = fa->parent) {
//     if (!ISBALANCE(*fa)) {
//       fa = trace(*fa) = BST<T>::rotate(tallerChild(tallerChild(fa)));
//     }
//     BST<T>::updateHeight(fa);
//   }
//   return true;
// }

#endif // !__AVL_IMPLE__
