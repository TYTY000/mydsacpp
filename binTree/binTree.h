#ifndef __BINTREE__
#define __BINTREE__

#include "./binNode.h"

template <typename T>
class BinTree {
  protected:
    Rank _size;  BinNodePosi<T> _root;
    virtual Rank updateHeight( BinNodePosi<T> p );
    void updateHeightAbove ( BinNodePosi<T> p );
public:
  BinTree() :_size (0), _root( nullptr ) { }
  ~BinTree() { if ( _size > 0 ) remove ( _root ); }
  BinTree(BinTree &&) = delete;
  BinTree(const BinTree &) = delete;
  BinTree &operator=(BinTree &&) = delete;
  BinTree &operator=(const BinTree &) = delete;
  bool operator< ( const BinTree<T>& t ) 
  { return _root && t._root && ( _root < t._root ); } //
  bool operator== ( const BinTree<T>& t ) 
  { return _root && t._root && ( _root == t._root ); } //

  Rank size() const { return _size; }
  bool empty() const { return !_root; }
  BinNodePosi<T> root() const { return _root; }

  BinNodePosi<T> insert ( const T& e );
  BinNodePosi<T> insert ( const T& e ,BinNodePosi<T> n );
  BinNodePosi<T> insert ( BinNodePosi<T> n, const T& e );
  BinNodePosi<T> attachAsLC ( BinNodePosi<T> n, BinTree<T>* S );
  BinNodePosi<T> attachAsRC ( BinNodePosi<T> n, BinTree<T>* S );
  Rank remove ( BinNodePosi<T> );
  BinTree<T>* secede ( BinNodePosi<T> );

  template <typename VST> void travLv ( VST& visit )
  {
    if ( _root ) _root->travLv ( visit );
  }

  template <typename VST> void travPre ( VST& visit )
  {
    if ( _root ) _root->travPre ( visit );
  }
  
  template <typename VST> void travMi ( VST& visit )
  {
    if ( _root ) _root->travMi ( visit );
  }
  
  template <typename VST> void travPo ( VST& visit )
  {
    if ( _root ) _root->travPo ( visit );
  }
};

extern int c;

#include <boost/core/demangle.hpp>

// template <typename T> struct Print{
//   virtual void operator () ( T& e )
//   {
//     std::cout << "No." << c << " : " << e << "\t";
//     ++c;
//     if (c % 5 == 0) {std::cout << '\n';}
//   }
// };


// template <typename T>
// std::ostream& operator<< ( std::ostream& os, BinTree<T>& bt )
// {
//   Print<T> pr;
//   os << boost::core::demangle( typeid(bt).name() ) << "\t";
//   os << boost::core::demangle( typeid(T).name() ) << "\tSize:\t" << bt.size() << "\nprint by: ";
//   switch (rand() % 4) {
//     case 1 : 
//       std::cout << "pre\n{" << std::endl;bt.travPre( pr );c = 0; break;
//     case 2 :
//       std::cout << "mid\n{" << std::endl;bt.travMi( pr ); c = 0; break;
//     case 3 :
//       std::cout << "post\n{" << std::endl;bt.travPo( pr ); c = 0; break;
//     default:
//       std::cout << "level\n{" << std::endl;
//       bt.travLv( pr );  c = 0;
//       break;
//   }
//   os << "\n}\n" << std::endl;
//   return os;
// }

#include "binTree_imple.h"
#endif // !__BINTREE__
