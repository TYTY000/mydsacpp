#ifndef __QUEUE__
#define __QUEUE__

#include "../list/list.h"

template <typename T>
class Queue: public List<T> {
  public:
    void enqueue ( const T& e ) { List<T>::insertAsLast( e ); }
    T dequeue () { return List<T>::remove ( List<T>::first () ); }
    T& peek () { return List<T>::first()->data; }
};

#endif // !__QUEUE__
