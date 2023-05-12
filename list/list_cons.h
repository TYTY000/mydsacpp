#ifndef __list_cons__
#define __list_cons__

template <typename T>
List<T>::List( const ListNodePosi<T> p, Rank n )
{
  copyNodes( p, n );
}

template <typename T>
List<T>::List( const List<T>& L, Rank r, Rank n)
{
  ListNodePosi<T> p = L.first();
  while ( r-- > 0 ) p = p->next;
  copyNodes( p, n );
}

template <typename T>
List<T>::List( const List<T>& L )
{
  copyNodes( L.first(), L._size );
}
#endif // !__list_cons__
