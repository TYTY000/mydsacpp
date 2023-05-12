#ifndef __BINNODE_SUCC__
#define __BINNODE_SUCC__

template <typename T>
BinNodePosi<T> BinNode<T>:: pred()
{
  BinNodePosi<T> t = this;
  if ( lc ) {
    t = lc;
    while ( HasRChild( t ) ) t = t->rc;
  } else {
    while ( IsLChild ( t ) ) {
      t = t->parent;
    }
    t = t->parent;
  }
  return t;
}

template <typename T>
BinNodePosi<T> BinNode<T>:: succ()
{
  BinNodePosi<T> t = this;
  if ( rc ) {
    t = rc;
    while ( HasLChild( t ) ) t = t->lc;
  } else {
    while ( IsRChild( t ) ) t = t->parent;
      t = t->parent;
  }
  return t;
}

#endif // !__BINNODE_SUCC__
