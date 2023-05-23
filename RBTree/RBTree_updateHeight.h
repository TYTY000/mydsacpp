/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-20 17:10:08
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-21 19:12:11
 */

#ifndef __RBTREE_HEIGHT_H__
#define __RBTREE_HEIGHT_H__

#include <algorithm>
template <typename T> Rank RBTree<T>::updateHeight(BinNodePosi<T> n) {
  n->height = std::max(stature(n->lc), stature(n->rc));
  return IsBlack(n) ? n->height++ : n->height;
}

#endif // !__RBTREE_REMOVE_H__
