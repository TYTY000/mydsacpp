#ifndef __list_dest__
#define __list_dest__

template <typename T>
List<T>::~List()
{
  clear();
  delete head;
  delete tail;
}

#endif
