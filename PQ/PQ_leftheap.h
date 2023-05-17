/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-12 12:17:10
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-14 23:54:17
 */

#include "./PQ.h"
#include "../binTree/binTree.h"

// LeftHeap belongs to BinTree, and satisfy following property:
//            1.npl descending;
//            2.npl( lc(x) ) >= npl( rc(x) );
//            3.npl(x) = length(x.right);
//
// how to merge 2 heaps maintaining LeftHeap?
// 1.merge A_R with B, B_R to A_R;
// 2.if A_L and A_R violate rule 2, swap;
// 3. update npl of A;
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
