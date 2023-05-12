#ifndef __list_bracket__
#define __list_bracket__

template <typename T>
ListNodePosi<T> List<T>::operator[]( Rank r ) const
{
  ListNodePosi<T> p = first();
  while ( r-- > 0 )
    p = p->next;
  return p;
}

#endif // !__list_bracket__
