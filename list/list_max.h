#ifndef __list_max__
#define __list_max__

template <typename T>
ListNodePosi<T> List<T>::takeMax( ListNodePosi<T> p, Rank n )
{
  ListNodePosi<T> max = p;
  for(ListNodePosi<T> cur = p; n > 1; --n)
    if( !lt( ( cur = cur->next )->data, max->data ) )
      max = cur;
  return max;
}

#endif // !__list_max__
