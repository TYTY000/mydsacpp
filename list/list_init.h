#ifndef __list_init__
#define __list_init__

template <typename T>
void List<T>::init()
{
  head = new ListNode<T>;
  tail = new ListNode<T>;
  head->next = tail; head->prev = NULL;
  tail->prev = head; tail->next = NULL;
  _size = 0;
}

#endif // !__list_init__
