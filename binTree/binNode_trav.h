#ifndef __BINNODE_TRAV__
#define __BINNODE_TRAV__

#include "../stack/stack.h"

#include "./binNode_travPre.h"

template <typename T> template <typename VST> 
  void BinNode<T>::travPre ( VST& visit )
{
  switch ( rand() % 3) {
    case 1 : travPre_I1 ( this, visit ); break;
    case 2 : travPre_I2 ( this, visit ); break;
    default: travPre_R ( this, visit );  break;
  }
}

#include "./binNode_travMi.h"

template <typename T> template <typename VST> 
  void BinNode<T>::travMi ( VST& visit )
{
  switch ( rand() % 5 ) {
    case 1: travMi_I1 ( this, visit ); break;
    case 2: travMi_I2 ( this, visit ); break;
    case 3: travMi_I3 ( this, visit ); break;
    case 4: travMi_I4 ( this, visit ); break;
    default:
      travMi_R ( this, visit );
      break;
  }
}

#include "./binNode_travPo.h"

template <typename T> template <typename VST> 
  void BinNode<T>::travPo ( VST& visit )
{
  switch ( rand() % 2 ) {
    case 1: travPo_I ( this, visit ); break;
    default : travPo_R ( this, visit ); break;
  }
}

#include "./binNode_travLv.h"

#endif // !__BINNODE_TRAV__
