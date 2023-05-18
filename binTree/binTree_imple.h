#ifndef __BINTREE_IMPLE__
#define __BINTREE_IMPLE__

template <typename T>
Rank BinTree<T>::updateHeight( BinNodePosi<T> p )
{
  return p->height = 1 + std::max( stature(p->lc), stature(p->rc) );
}

template <typename T>
void BinTree<T>::updateHeightAbove ( BinNodePosi<T> p )
{
  while (p) { Rank n = p->height; if( n == updateHeight(p) ) break; p = p->parent; }
}

template <typename T>
BinNodePosi<T> BinTree<T>::insert( const T& e )
  {
    _size = 1; return _root = new BinNode<T>( e );
  }

template <typename T>
BinNodePosi<T> BinTree<T>::insert ( const T& e , BinNodePosi<T> n)
  {
    _size ++; n->insertAsLC( e ); updateHeightAbove( n ); return n->lc;
  }

template <typename T>
BinNodePosi<T> BinTree<T>::insert ( BinNodePosi<T> n, const T& e )
  {
    _size ++; n->insertAsRC( e ); updateHeightAbove( n ); return n->rc;
  }

template <typename T>
BinNodePosi<T> BinTree<T>::attachAsLC( BinNodePosi<T> n, BinTree<T>* S )
  {
    if (( n->lc = S->_root )) n->lc->parent = n;
    _size += S->_size; updateHeightAbove( n );
    S->_root = nullptr; S->_size = 0; 
    if ( S ) delete S; S = nullptr; return n;
  }

template <typename T>
BinNodePosi<T> BinTree<T>::attachAsRC( BinNodePosi<T> n, BinTree<T>* S )
  {
    if (( n->rc = S->_root )) n->rc->parent = n;
    _size += S->_size; updateHeightAbove( n );
    S->_root = nullptr; S->_size = 0; 
    if ( S ) delete S; S = nullptr; return n;
  }

template <typename T>
Rank BinTree<T>::remove( BinNodePosi<T> n )
  {
    trace( n ) = nullptr;
    updateHeightAbove( n );
    Rank r = removeAt( n );
    _size -= r; return r;
  }

template <typename T>
static Rank removeAt( BinNodePosi<T> n )
{
  if (!n) return 0;
  static int num = 0;
  Rank r = 1 + removeAt( n->lc ) + removeAt ( n->rc );
  return r;
}


template <typename T>
BinTree<T>* BinTree<T>::secede( BinNodePosi<T> n )
  {
    trace( n ) = nullptr;
    updateHeightAbove( n->parent );
    BinTree<T>* S = new BinTree<T>;
    S->_root = n; n->parent = nullptr;
    S->_size = n->size(); _size -= S->_size; return S;
  }

#endif // !__BINTREE_IMPLE__
