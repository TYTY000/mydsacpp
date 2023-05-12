#ifndef __DEQUE__
#define __DEQUE__

#include "../queue/queue.h"

template <typename T>
class deque: public List<T> {
  public:
    T& front() { return List<T>::first(); }
    T& rear() { return List<T>::last(); }
    T removeFront() { return List<T>::remove( front() ); }
    T removeRear() { return List<T>::remove( rear() ); }
    void insertFront ( const T& e ) { return List<T>::insertAsFirst(e); }
    void insertRear ( const T& e ) { return List<T>::insertAsLast(e); }
    void reverse()
    {
      auto f = front(); auto r = rear();
      std::swap( f->data, r->data );
      f = f->next; r = r->prev;
    }
};

#endif // !__DEQUE__
