/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-12 12:17:10
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-12 12:25:39
 */

#include "./PQ.h"
#include "../binTree/binTree.h"

template<typename T>
class PQ_LeftHeap : public PQ<T>, public BinTree<T>
{
  public:
    PQ_LeftHeap() {}
    PQ_LeftHeap( T* E, int n ){
      for (int i = 0; i < n; i++) {
        insert( E[i] );
      }    
    }
    void insert( T e );
    T getMax();
    T delMax();
  };
