#ifndef __AVL_IMPLE__
#define __AVL_IMPLE__

#define BALANCED(X) ( stature( (X)->lc ) == stature ( (X)->rc ) )
#define BALDIFF(X) ( stature( (X)->lc ) - stature( (X)->rc ) )
#define ISBALANCE(X) ( ( BALDIFF(X) < 2 ) && ( BALDIFF(X) > -2 ) )

#define tallerChild(X) ( \
    (BALDIFF(X) > 0) ? (X)->lc : (\
    (BALDIFF(X) < 0) ? (X)->rc : (\
    IsLChild(X) ? (X)->lc : (X)->rc\
    )\
    )\
)

template <typename T>
BinNodePosi<T> AVL<T>::insert ( const T& e )
{
  BinNodePosi<T> n = search(e); if ( n ) return n;
  BinNodePosi<T> c = new BinNode<T> ( e, BST<T>::_s ); BinTree<T>::_size++;
  for ( BinNodePosi<T> fa = BST<T>::_s; fa; fa = fa->parent ) {
    if ( !ISBALANCE( fa ) )
    {
      trace ( fa ) = BST<T>::rotate( tallerChild( tallerChild (fa) ) );
      break;
    }
    BST<T>::updateHeight( fa );
  }
  return c;
}

template <typename T>
bool AVL<T>::remove ( const T& e )
{
  BinNodePosi<T> n = search(e); if (!n) return false;
  BST<T>::removeAt(n); BST<T>::_size--;
  for (BinNodePosi<T> fa = BST<T>::_s; fa; fa = fa->parent) {
    if( !ISBALANCE( fa ) )
    {
      fa = trace(fa) = BST<T>::rotate( tallerChild (tallerChild (fa) ) );
      break;
    }
    BST<T>::updateHeight(fa);
  }
  return true;
}

#endif // !__AVL_IMPLE__
