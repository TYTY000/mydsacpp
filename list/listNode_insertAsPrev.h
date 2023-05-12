#ifndef __node_prev__
#define __node_prev__

template <typename T>
ListNodePosi<T> ListNode<T>::insertAsPrev( const T& e )
{
  ListNodePosi<T> p = new ListNode( e, prev, this );
  prev->next = p; prev = p;
  return p;
}

#endif // !__node_prev__
