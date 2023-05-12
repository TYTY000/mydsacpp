#ifndef __list_merge__
#define __list_merge__

template <typename T>
void List<T>::merge( ListNodePosi<T> p, Rank n, List<T>& L, ListNodePosi<T> q, Rank m)
{
  ListNodePosi<T> pp = p->prev;
  while ( ( m > 0 ) && ( q != p ) )
    if ( ( n > 0 ) && ( p->data <= q->data ) ) 
    {
      p = p -> next;
      n--;
    } else 
    {
      insert( L.remove( ( q = q->next )->prev ), p );
      m--;
    }
  p = pp->next;
}

template <typename T>
void List<T>::mergeSort( ListNodePosi<T>& p, Rank n )
{
  if ( n < 2 ) return;
  Rank m = n >> 1;
  ListNodePosi<T> q = p;
  for (Rank i = 0; i < m; i++)  q = q->next;
/*
  -----------------------------------------
  p                   q
                      m        n - m      n
  -----------------------------------------
  */
  mergeSort( p, m ); mergeSort( q, n - m );
  merge( p, m, *this, q, n - m );
}
#endif // !__list_merge__
