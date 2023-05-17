/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-12 08:56:02
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-12 14:55:29
 */

#ifndef __PQ_VECTOR_IMPLE__
#define __PQ_VECTOR_IMPLE__

#define INHEAP( n, i ) ( ( i < n ) && ( i > -1 ) )
#define PARENT( i ) ( ( i - 1 ) >> 1 )
#define LCHILD( i ) ( (i) << 1 + 1 )
#define RCHILD( i ) ( (i + 1) << 1 )
#define LASTPARENT(n) ( PARENT( n - 1 ) )
#define HASPARENT(i) ( i - 1 )
#define HASLCHILD(n, i) ( INHEAP ( n, LCHILD(i) ) )
#define HASRCHILD(n, i) ( INHEAP ( n, RCHILD(i) ) )
#define BIGGER(PQ, i, j) ( lt ( PQ[i], PQ[j] ) ? j : i )
#define PROPERPARENT(PQ, i, j) \
        ( HASRCHILD(n, i) ? BIGGER(PQ, BIGGER(PQ, i, LCHILD(i)), RCHILD(i) ) : \
        ( HASLCHILD(n, i) ? BIGGER(PQ, i, LCHILD(i)) : i ) \
        )

template <typename T>
Rank percolateDown( T* A, Rank n, Rank i )
{
  Rank j;
  while ( i != ( j = PROPERPARENT( A, n, i) ) ) {
    std::swap( A[i], A[j] );
    i = j;
  }
  return i;
}

template <typename T>
Rank percolateUp( T* A, Rank i )
{
  while ( i > 0 ) {
    Rank j = PARENT(i);
    if ( lt ( A[i], A[j] ) ) break;
    std::swap( A[i], A[j] );
    i = j;
  }
  return i;
}

template <typename T>
void heapify( T* A, Rank n )
{
  for ( Rank i = n / 2 - 1; i != -1; i--) {
    percolateDown( A, n, i );
  }
}

#endif // !__PQ_VECTOR_IMPLE__
