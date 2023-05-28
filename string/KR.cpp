/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-28 21:09:40
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-28 21:14:42
 */

#include "../hashtable/HashTable.cpp"
#include "MyString.cpp"
#include <algorithm>
#include <boost/container_hash/hash.hpp>
#include <boost/functional/hash.hpp>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

void tableInit(HashTable<int, size_t> &table, const string &str,
               const string &p) {
  int count = str.length() - p.length();
  int lenp = p.length();
  string substr;
  boost::hash<string> h;
  for (size_t i = 0; i < count; i++) {
    substr = str.substr(i, lenp);
    cout << "Hash of substr : " << substr << " is : " << h(substr) << endl;
    table.put(h(substr), i);
  }
  std::cout << "Table init completed ! " << std::endl;
}

void KR(HashTable<int, size_t> &table, const string &str, const string &p) {
  boost::hash<string> h;
  auto hp = h(p);
  cout << "Hash of pattern : " << p << " is : " << hp << endl;
  size_t *posi = table.get(hp);
  if (posi == nullptr)
    std::cout << "Not found ! no hash code match!" << std::endl;
  else {
    std::cout << "Matched at ? " << *posi << std::endl;
    MyString str1(str.substr(*posi, p.length()));
    MyString str2(p);
    if (str1 == str2) {
      std::cout << "perfect match!" << std::endl;
      cout << str.substr(0, *posi) << '\t' << str.substr(*posi, p.length())
           << '\t' << str.substr(*posi + p.length(), str.length()) << endl;
      std::cout << str2 << std::endl;
    } else {
    std::cout << "fake match!" << std::endl;
    table.remove(hp);
    }
  }
}

int main(int argc, char *argv[]) {
  string str = "asdfsadsadfsdfasxdfasdfasd";
  string p = "dfsad";
  HashTable<int, size_t> table;
  tableInit(table, str, p);
  KR(table, str, p);
}
