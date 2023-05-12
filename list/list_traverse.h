#ifndef __list_traverse__
#define __list_traverse__

template <typename T>
void List<T>::traverse( void(*visit)(T&) )
{
  for( ListNodePosi<T> p = head->next; p != tail ; p = p->next )
    visit( p->data );
}

template <typename T> template <typename VST>
void List<T>::traverse( VST& visit )
{
  for( ListNodePosi<T> p = head->next; p != tail ; p = p->next )
    visit( p->data );
}

#endif // !__list_traverse__
