#ifndef __BST__
#define __BST__

#include "../binTree/binTree.h"

template <typename T>
class BST : public BinTree<T> {
public:
virtual BinNodePosi<T>& search ( const T& e );
virtual BinNodePosi<T> insert ( const T& e );
virtual bool remove ( const T& e );

protected:
BinNodePosi<T> rotate ( BinNodePosi<T> );
BinNodePosi<T> rotateGFS( BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>,
 BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T>, BinNodePosi<T> );
BinNodePosi<T> _s;
};


#include "BST_imple.h"

#endif // !__BST__