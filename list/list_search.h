#ifndef __list_search__
#define __list_search__

template <typename T>
ListNodePosi<T> List<T>::search( const T& e, Rank n, ListNodePosi<T> p) const
{
  do
  {
    p = p->prev; --n;
  } while( ( e < p->data ) && ( n != -1 ));
  return p;
}

#endif // !__list_search__
