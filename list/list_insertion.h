#ifndef __list_insertion__
#define __list_insertion__

#include "listNode_imple.h"
template <typename T>
void List<T>::insertionSort( ListNodePosi<T> p, Rank n )
{
  for( Rank r = 0; r < n; ++r)
  {
    insert( search( p->data, r, p ) , p->data );
    p=p->next; remove( p->prev );
  }
}

#endif // !__list_insertion__
