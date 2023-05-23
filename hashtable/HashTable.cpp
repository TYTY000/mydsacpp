/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-24 19:27:11
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-25 18:18:39
 */

#include "HashTable.h"
#include <algorithm>
#include <cstring>

int cnt = 78498;
std::string file = "./prime-1000000.txt";

static Rank hashCode(char c) { return (Rank)c; }
static Rank hashCode(int k) { return (Rank)k; }
static Rank hashCode(long long i) { return (Rank)((i >> 32) + (int)i); }
static Rank hashCode(char s[]) {
  Rank n = strlen(s);
  Rank h = 0;
  for (Rank i = 0; i < n; i++) {
    h = (h << 5) |
        (h >> 27);
    h += s[i];
  }
  return h;
}

/*
 * read line into v.
 * n -> lines of numbers of file.
 */

static void readline(int n, Vector<int> &v, string file) {
  ifstream ifs;
  ifs.open(file);
  if (ifs.fail()) {
    cout << "Error: " << file << endl;
    exit(-1);
  }
  string line;
  for (int i = 0; i < n; i++) {
    getline(ifs, line);
    v.insert(stoi(line));
  }
}
/*
 * c -> upper bound for prime
 * n -> lines of file
 * file -> filedir
 * return the value of biggest integer <= c
 */
static int binSearch(Vector<int> &v, int n, int c) {
  int lo = 0, hi = n;
  int mi = 0;
  while (hi > lo) {
    mi = (lo + hi) >> 1;
    (c < v[mi]) ? hi = mi : lo = mi + 1;
  }
  return v[lo - 1];
}

/*
 * c -> upper bound for prime
 * n -> lines of file
 * file -> filedir
 * return the value of biggest integer <= c
 */
static int PrimeNLT(Vector<int> &v, int n, int c) { return binSearch(v, n, c); }

template <typename K, typename V> HashTable<K, V>::HashTable(Rank c) {
  readline(cnt, v, file);
  M = PrimeNLT(v, cnt, c);
  N = 0;
  dic = new Entry<K, V> *[M];
  memset(dic, 0, sizeof(Entry<K, V> *) * M);
}

template <typename K, typename V> HashTable<K, V>::~HashTable() {
  for (Rank i = 0; i < M; i++) {
    if (dic[i])
      delete dic[i];
  }
  delete[] dic;
}

template <typename K, typename V> void HashTable<K, V>::rehash() {
  Rank oldM = M;
  Entry<K, V> **oldDic = dic;
  M = PrimeNLT(v, cnt, 4 * N);
  N = 0;
  dic = new Entry<K, V> *[M];
  memset(dic, 0, sizeof(Entry<K, V> *) * M);
  for (Rank i = 0; i < oldM; i++) {
    if (oldDic[i] != nullptr)
      put(oldDic[i]->key, oldDic[i]->value);
  }
  delete[] oldDic;
}

template <typename K, typename V> Rank HashTable<K, V>::probe4Free(const K &k) {
  Rank r = hashCode(k) % M;
  while (dic[r] != nullptr) {
    r = (r + 1) % M;
  }
  return r;
} // find a bucket to fill.

template <typename K, typename V> Rank HashTable<K, V>::probe4Hit(const K &k) {
  Rank r = hashCode(k) % M;
  while (dic[r] != nullptr && k != dic[r]->key) {
    r = (r + 1) % M;
  }
  return r;
} // find a bucket matched.

template <typename K, typename V> bool HashTable<K, V>::put(K k, V v) {
  if (dic[probe4Hit(k)])
    return false;
  Rank r = probe4Free(k);
  dic[r] = new Entry<K, V>(k, v);
  ++N;
  if (N * 3 > M)
    rehash();
  return true;
}

template <typename K, typename V> V *HashTable<K, V>::get(K k) {
  Rank r = probe4Hit(k);
  return dic[r] ? &(dic[r]->value) : NULL;
}

template <typename K, typename V> bool HashTable<K, V>::remove(K k) {
  Rank r = probe4Hit(k);
  if (!dic[r])
    return false;
  dic[r] = nullptr;
  N--;
  if (N == 0) { M = 0;return true; }
  if (N * 2 < M)
    rehash();
  return true;
}
