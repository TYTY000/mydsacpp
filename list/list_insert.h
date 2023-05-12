#ifndef __list_insert__
#define __list_insert__

template <typename T>
ListNodePosi<T> List<T>::insert( ListNodePosi<T> p, const T& e )
{
  _size++;  return p->insertAsNext(e);
}
template <typename T>
ListNodePosi<T> List<T>::insert( const T& e, ListNodePosi<T> p )
{
  _size++;  return p->insertAsPrev(e);
}
template <typename T>
ListNodePosi<T> List<T>::insertAsFirst(const T& e)
{
  _size++; return head->insertAsNext(e);
}

template <typename T>
ListNodePosi<T> List<T>::insertAsLast(const T& e)
{
  _size++; return tail->insertAsPrev(e);
}

#endif // !__list_insert__
