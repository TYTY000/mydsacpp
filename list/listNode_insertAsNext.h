#ifndef __node_next__
#define __node_next__

template <typename T>
ListNodePosi<T> ListNode<T>::insertAsNext( const T& e )
{
  ListNodePosi<T> p = new ListNode( e, this, next );
  next->prev = p; next = p;
  return p;
}

#endif // !__node_next__
