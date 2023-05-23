/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-23 22:37:13
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-24 15:57:50
 */

#ifndef __ENTRY__
#define __ENTRY__

template <typename K, typename V> struct Entry {
  K key;
  V value;
  Entry(K k=K(), V v=V()) : key(k), value(v) {};
  Entry(const Entry<K, V> &e) : key(e.key), value(e.value) {};
  bool operator==(const Entry<K, V>& e) { return key == e.key;}
  bool operator<(const Entry<K, V>& e) { return key < e.key;}
  bool operator>(const Entry<K, V>& e) { return key > e.key;}
  bool operator!=(const Entry<K, V>& e) { return key != e.key;}
  bool operator<=(const Entry<K, V>& e) { return key <= e.key;}
  bool operator>=(const Entry<K, V>& e) { return key >= e.key;}
};

#endif // !__ENTRY__
