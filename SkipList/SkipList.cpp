/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-24 16:32:07
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-24 17:19:44
 */

#include "SkipList.h"

template <typename K, typename V> V *Skiplist<K, V>::get(K k) {
  QNode<Entry<K, V>> *p = search(k);
  return (p->prev && p->entry.key == k) ? &(p->entry.value) : NULL;
}

template <typename K, typename V> bool Skiplist<K, V>::put(K k, V v) {
  Entry<K, V> e = Entry<K, V>(k, v);
  QNodePosi<Entry<K, V>> p = search(k);
  ListNodePosi<Quadlist<Entry<K, V>> *> qlist =
      List<Quadlist<Entry<K, V>> *>::last();
  QNodePosi<Entry<K, V>> b = qlist->data->insert(e, p);
  while (rand() & 1) {
    while (p->prev && !p->above)
      p = p->prev;
    if (!p->prev && !p->above) {
      List<Quadlist<Entry<K, V>> *>::insertAsFirst(new Quadlist<Entry<K, V>>);
      List<Quadlist<Entry<K, V>> *>::first()->data->header->below =
          qlist->data->header;
      qlist->data->header->above =
          List<Quadlist<Entry<K, V>> *>::first()->data->header;
    }
    p = p->above;
    qlist = qlist->prev;
    b = qlist->data->insert(e, p, b);
  }
  return true;
}

template <typename K, typename V> bool Skiplist<K, V>::remove(K k) {
  QNodePosi<Entry<K, V>> p = search(k);
  if (!p->prev || (k != p->entry.key))
    return false;
  ListNodePosi<Quadlist<Entry<K, V>> *> qlist =
      List<Quadlist<Entry<K, V>> *>::last();
  while (p->above) {
    qlist = qlist->prev;
    p = p->above;
  }
  do {
    QNodePosi<Entry<K, V>> lower = p->below;
    qlist->data->remove(p);
    p = lower;
    qlist = qlist->next;
  } while (qlist->next);
  while ((1 < height()) &&
         (List<Quadlist<Entry<K, V>> *>::first()->data->_size < 1)) {
    List<Quadlist<Entry<K, V>> *>::remove(
        List<Quadlist<Entry<K, V>> *>::first());
    List<Quadlist<Entry<K, V>> *>::first()->data->header->above = NULL;
  }
  return true;
}

template <typename K, typename V>
QNodePosi<Entry<K, V>> Skiplist<K, V>::search(K k) {
  for (QNodePosi<Entry<K, V>> p =
           List<Quadlist<Entry<K, V>> *>::first()->data->header;
       ;)
    if ((p->next->next) && (p->next->entry.key <= k))
      p = p->next;
    else if (p->below)
      p = p->below;
    else
      return p;
}
