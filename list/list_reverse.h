#ifndef __list_reverse__
#define __list_reverse__

#include <bits/stdc++.h>
template <typename T>
void List<T>::reverse()
{
  ListNodePosi<T> p = head;
  ListNodePosi<T> q = tail;
  for( int i = 1; i < _size; i += 2)
  {
    std::swap( ( p = p->next )->data , ( q = q->prev )->data );
  }
}

#endif // !__list_reverse__
