#ifndef __list_find__
#define __list_find__

template <typename T>
ListNodePosi<T> List<T>::find( const T& e, Rank n, ListNodePosi<T> p) const
{
  while ( n-- > 0 )
    if ( e == ( p = p->prev )->data ) return p;
  return NULL;
}

#endif // !__list_find__
