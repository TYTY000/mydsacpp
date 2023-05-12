#ifndef __list_copynode__
#define __list_copynode__

template <typename T>
void List<T>::copyNodes( ListNodePosi<T> p, Rank n )
{
  init();
  while (n--){
    insertAsLast( p->data );
    p = p->next;
  }
}

#endif
