/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-24 16:28:28
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-24 16:53:47
 */

#ifndef __SKIPLIST__
#define __SKIPLIST__

#include "../list/list.h"
#include "Dictionary.h"
#include "Entry.h"
#include "QuadList.h"

template <typename K, typename V>
class Skiplist : public Dictionary<K, V>, public List<Quadlist<Entry<K, V>> *> {
public:
  Skiplist() {
    List<Quadlist<Entry<K, V>> *>::insertAsFirst(new Quadlist<Entry<K, V>>);
  };
  QNodePosi<Entry<K, V>> search(K);
  Rank size() const {
    if (List<Quadlist<Entry<K, V>> *>::empty())
      return 0;
    else
      return List<Quadlist<Entry<K, V>> *>::last()->data->size();
  }
  Rank height() { return List<Quadlist<Entry<K, V>> *>::size(); }
  V *get(K);
  bool put(K, V);
  bool remove(K);
};

#endif // !__SKIPLIST__
