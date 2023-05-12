#ifndef __list_selection__
#define __list_selection__

template <typename T>
void List<T>::selectionSort( ListNodePosi<T> p, Rank n )
{
  ListNodePosi<T> h = p->prev; ListNodePosi<T> t = p;
  for ( int i = 0; i < n; ++i ){ t = t->next; }
  while ( n > 1 )
  {
    ListNodePosi<T> max = takeMax( h->next, n );  //find max
    if ( max != tail->prev ) std::swap(max->data, t->prev->data);
    //insert ( remove(max), t ); // insert before tail
    t = t->prev; --n;  //tail iterate
  }
}

#endif // !__list_selection__
