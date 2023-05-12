#ifndef __list_deduplicate__
#define __list_deduplicate__

template <typename T>
Rank List<T>::deduplicate()
{
  if( _size < 2 ) return 0;
  int oldsize = _size;
  ListNodePosi<T> p = head; Rank r = 0;
  while ( (p = p->next) != tail )
  {
    ListNodePosi<T> q = find( p->data, r, p );
    q? remove(q): r++;
  }
  return oldsize - _size;
}

#endif // !__list_deduplicate__
