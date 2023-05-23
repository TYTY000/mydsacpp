/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-24 08:25:42
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-24 08:28:15
 */

#ifndef __DICTIONARY__
#define __DICTIONARY__

using Rank = unsigned int;

template <typename K,typename V>
struct Dictionary {
  virtual Rank size() const = 0;
  virtual bool put(K,V) = 0;
  virtual V* get(K k) = 0;
  virtual bool remove(K k) = 0;
};

#endif // !__DICTIONARY__
