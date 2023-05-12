#ifndef __BINNODE_TRAVMI__
#define __BINNODE_TRAVMI__

template <typename T, typename VST>
void travMi_R ( BinNodePosi<T> n, VST& visit )
{
  if (!n) return;
  travMi_R ( n->lc, visit );
  visit ( n->data );
  travMi_R ( n->rc, visit );
}

template <typename T>
static void goAlongLeftBreach( BinNodePosi<T> n, Stack< BinNodePosi<T> >& S )
{
  while ( n ) {
    S.push( n );
    n = n->lc;
  }
}

template <typename T, typename VST>
void travMi_I1 ( BinNodePosi<T> n, VST& visit )
{
  Stack< BinNodePosi<T> > S;
  while ( true ) {
    goAlongLeftBreach ( n, S );
    if ( S.empty() ) break;
    n = S.pop(); visit ( n->data );
    n = n->rc;
  }
}

template <typename T, typename VST>
void travMi_I2 ( BinNodePosi<T> n, VST& visit )
{
  Stack< BinNodePosi<T> > S;
  while ( true ) {
    if ( n )  {
      S.push( n );
      n = n->lc;
    }else if ( !S.empty() ) {
      n = S.pop();
      visit ( n->data );
      n = n->rc;
    }else {
      break;
    }
  }
}

#include "./binNode_succ.h"


template <typename T, typename VST>
void travMi_I3 ( BinNodePosi<T> n, VST& visit )
{
  bool flag = false;
  while ( true ) {
    if ( !flag && HasLChild ( n ) )
      n = n->lc;
    else {
      visit ( n->data );
      if( HasRChild ( n ) ) {
        n = n->rc;
        flag = false;
      } else {
        if ( !( n = n->succ() ) ) break;
        flag = true;
      }
    }
  }
}

template <typename T, typename VST>
void travMi_I4 ( BinNodePosi<T> n, VST& visit )
{
  while ( true ) {
    if ( HasLChild ( n ) )
      n = n->lc;
    else {
      visit ( n->data );
      while ( !HasRChild ( n ) ) {
        if ( ! ( n = n->succ() ) ) return;
        else visit ( n->data );
      }
      n = n->rc;
    }
  }
}

#endif // !__BINNODE_TRAVMI__
