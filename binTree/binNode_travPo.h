#ifndef __BINNODE_POST__
#define __BINNODE_POST__

template <typename T, typename VST>
void travPo_R ( BinNodePosi<T> n, VST& visit )
{
  if (!n) return;
  travPo_R ( n->lc, visit );
  travPo_R ( n->rc, visit );
  visit ( n->data );
}

template <typename T>
void gotoHLVFL ( Stack< BinNodePosi<T> >& S )
{
  while ( BinNodePosi<T> n = S.peek() ) {
    if ( HasLChild ( n ) ){
      if ( HasRChild ( n ) ) S.push( n ->rc );
      S.push( n->lc );
    } else {
      S.push ( n->rc );
    }
  }
  S.pop();
}

template <typename T, typename VST>
void travPo_I ( BinNodePosi<T> n, VST& visit )
{
  Stack< BinNodePosi<T> > S;
  if ( n ) S.push( n );
  while ( !S.empty() ) {
    if ( S.peek() != n->parent )
      gotoHLVFL( S );
    n = S.pop(); visit ( n->data );
  }
}

#endif // !__BINNODE_POST__
