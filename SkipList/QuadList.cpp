#include "QuadList.h"

template <typename T> void Quadlist<T>::init() {
  header = new QNode<T>;
  trailer = new QNode<T>;
  header->next = trailer;
  header->prev = nullptr;
  trailer->prev = header;
  trailer->next = nullptr;
  header->above = trailer->above = nullptr;
  header->below = trailer->below = nullptr;
  _size = 0;
}

template <typename T>
QNodePosi<T> Quadlist<T>::insert(T const &e, QNodePosi<T> p, QNodePosi<T> b) {
  _size++;
  return p->insert(e, b);
}

template <typename T> T Quadlist<T>::remove(QNodePosi<T> p) {
  p->prev->next = p->next;
  p->next->prev = p->prev;
  _size--;
  T e = p->entry;
  delete p;
  return e;
}

template <typename T> int Quadlist<T>::clear() {
  int oldSize = _size;
  while (0 < _size)
    remove(header->next);
  return oldSize;
}

template <typename T> void Quadlist<T>::traverse(void (*visit)(T &)) {
  QNodePosi<T> p = header;
  while ((p = p->next) != trailer)
    visit(p->data);
}

template <typename T>
template <typename VST>
void Quadlist<T>::traverse(VST &visit) {
  QNodePosi<T> p = header;
  while ((p = p->next) != trailer)
    visit(p->data);
}
