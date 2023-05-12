#ifndef __BINNODE_TRAVPRE__
#define __BINNODE_TRAVPRE__

template <typename T, typename VST>
static void visitAlongLeftBranch( BinNodePosi<T> n, VST& visit, Stack< BinNodePosi<T> >& S )
{
  while ( n )
  {
    visit ( n-> data );
    S.push( n->rc );
    n = n-> lc;
  }
}

template <typename T, typename VST>
void travPre_R( BinNodePosi<T> n, VST& visit )
{
  if (!n) return;
  visit ( n->data );
  travPre_R ( n->lc, visit );
  travPre_R ( n->rc, visit );
}

template <typename T, typename VST>
void travPre_I1( BinNodePosi<T> n, VST& visit )
{
  Stack<BinNodePosi<T>> S;
  if ( n ) S.push( n );
  while ( !S.empty() ) {
    n = S.pop(); visit ( n->data );
    if ( HasRChild( n ) ) S.push( n->rc );
    if ( HasLChild( n ) ) S.push( n->lc );
  }
}

template <typename T, typename VST>
void travPre_I2( BinNodePosi<T> n, VST& visit )
{
  Stack < BinNodePosi<T> >  S;
  while (true) {
    visitAlongLeftBranch ( n, visit, S );
    if ( S.empty() ) break;
    n = S.pop();
  }
}

#endif // !__BINNODE_TRAVPRE__
