#ifndef __list_uniquify__
#define __list_uniquify__

template <typename T>
Rank List<T>::uniquify()
{
  if ( _size < 2 ) return 0;
  int oldsize = _size;
  ListNodePosi<T> p = first(); ListNodePosi<T> q;
  while( tail != ( q = p->next ) )
    if ( p->data != q->data ) p = q;
    else remove(q);
  return oldsize - _size;
}

#endif // !__list_uniquify__
