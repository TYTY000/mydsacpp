#ifndef __BINNODE_LV__
#define __BINNODE_LV__

#include "../queue/queue.h"

template <typename T> template <typename VST> 
  void BinNode<T>::travLv ( VST& visit )
{
  Queue< BinNodePosi<T> >  Q;
  Q.enqueue( this );
  while ( !Q.empty() ) {
    BinNodePosi<T> n = Q.dequeue();
    visit ( n->data );
    if ( HasLChild ( n ) ) Q.enqueue ( n->lc );
    if ( HasRChild ( n ) ) Q.enqueue ( n->rc );
  }
}

#endif // !__BINNODE_LV__
