#ifndef __list_remove__
#define __list_remove__

template <typename T>
T List<T>::remove( ListNodePosi<T> p )
{
  T e = p->data;
  p->prev->next = p->next;
  p->next->prev = p->prev;
  delete p;  --_size; 
  return e;
}


#endif // !__list_remove__
