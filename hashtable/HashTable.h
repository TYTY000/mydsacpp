/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-24 19:09:03
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-25 18:11:00
 */

#ifndef __HASHTABLE__
#define __HASHTABLE__

#include "../SkipList/Dictionary.h"
#include "../SkipList/Entry.h"
#include "../vector/vector.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using Rank = unsigned int;

template <typename K, typename V> class HashTable : public Dictionary<K, V> {
  friend class Print;

private:
  Entry<K, V> **dic;
  Rank M, N;
  Vector<int> v;

protected:
  void rehash();
  Rank probe4Free(const K &k); // find a bucket to fill.
  Rank probe4Hit(const K &k);  // find a bucket matched.
public:
  HashTable(Rank c = 5);
  ~HashTable();
  Rank size() const { return N; }
  bool put(K k, V v);
  V *get(K k);
  bool remove(K k);
};

#endif // !__HASHTABLE__
