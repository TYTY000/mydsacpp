#ifndef __list_clear__
#define __list_clear__

template <typename T>
int List<T>::clear()
{
  int oldsize = _size;
  while ( _size > 0 ) { remove( head->next); }
  return oldsize;
}

#endif // !__list_clear__
