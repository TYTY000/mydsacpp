#ifndef __BST_BASIC__
#define __BST_BASIC__


template <typename T>
BinNodePosi<T>& BST<T>::search( const T& e )
{
  if ( BST<T>::_root || e == BST<T>::_root->data )  { _s = nullptr; return BST<T>::_root; }
  for ( _s = BST<T>::_root; ; ) {
    BinNodePosi<T>& n = ( e < _s->data )? _s->lc : _s->rc;
    if ( !n || n->data == e ) return n; _s = n;
    // return nullptr or nodeposi  -->  a spot to insert....
  }
}

template <typename T>
BinNodePosi<T> BST<T>::insert ( const T& e )
{
  BinNodePosi<T>& n = search ( e );
  if ( n ) return n;
  n = new BinNode<T> ( e, _s );
  ++BST<T>::_size;
  this->updateHeightAbove (n);
  return n;
}

template <typename T>
static void next( BinNodePosi<T> n )
{
  return ( rand() % 2 ) ? (*n).succ() : (*n).pred();
}

template <typename T>
static BinNodePosi<T> removeAt ( BinNodePosi<T>& n, BinNodePosi<T>& s )
{
  // n could be leaf, single child or double child.
  // need a var to store succ. data swap succ & n.
  BinNodePosi<T> temp = n;
  BinNodePosi<T> succ = nullptr;
  if ( !HasLChild ( n ) )
    succ = n = n->rc;
  else if ( !HasRChild ( n ) )
    succ = n = n->lc;
  else { // leaf 
    temp = temp->succ();
    std::swap ( temp->data, n->data );
    BinNodePosi<T> tempPred = temp->parent;  // now need to safe delete temp.
    if ( tempPred == n ) //tempPred also leaf
      tempPred->rc = succ = temp->rc;
    else 
      tempPred->lc = succ = temp->rc;
  }
  s = temp->parent;
  if ( succ ) succ->parent = s;
  delete temp; return succ;
}

template <typename T>
bool BST<T>::remove ( const T& e )
{
  BinNodePosi<T>& n = search ( e );
  if ( !n ) return false; // no target
  removeAt( n, _s ); --BST<T>::_size;
  this->updateHeightAbove( _s );
  return true;
}

template <typename T>
BinNodePosi<T> BST<T>::rotateGFS (
    BinNodePosi<T> a, BinNodePosi<T> b, BinNodePosi<T> c,
    BinNodePosi<T> t1, BinNodePosi<T> t2, BinNodePosi<T> t3, BinNodePosi<T> t4
    )
{
  a->lc = t1; if ( t1 ) t1->parent = a;
  a->rc = t2; if ( t2 ) t2->parent = a; updateHeight( a );
  c->lc = t3; if ( t3 ) t3->parent = c;
  c->rc = t4; if ( t4 ) t4->parent = c; updateHeight( c );
  b->lc = a; a->parent = b;
  b->rc = c; c->parent = b; updateHeight ( b );
  return b;
}
//                   b
//            a            c
//      1          2     3        4

template <typename T>
BinNodePosi<T> BST<T>::rotate ( BinNodePosi<T> son )
{
  BinNodePosi<T> fa = son->parent;
  BinNodePosi<T> gf = fa->parent;
  if ( IsLChild( fa ) )
  {
    if ( IsLChild( son ) )
    {
      fa->parent = gf->parent;
      rotateGFS( son, fa, gf, son->lc, son->rc, fa->rc, gf->rc );
    }
    else {
      son->parent = gf->parent;
      rotateGFS( fa, son, gf, fa->lc, son->lc, son->rc, gf->rc );
    }
  } else {
    if ( IsLChild ( son ) ) {
      son->parent = gf->parent;
      rotateGFS( gf, son, fa, gf->lc, son->lc, son->rc, fa->rc );
    } else {
      fa->parent = gf->parent;
      rotateGFS( gf, fa, son, gf->lc, fa->lc, son->lc, son->rc );
    }
  }
}

#endif // !__BST_BASIC_
