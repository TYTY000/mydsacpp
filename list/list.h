#ifndef __LIST__
#define __LIST__
#include "listNode.h"
#include <iostream>

template <typename T>
class List 
{
  private:
    int _size; ListNodePosi<T> head, tail;
  protected:
    // function
    void init();
    int clear();
    void copyNodes( ListNodePosi<T>, Rank );
    void merge( ListNodePosi<T>, Rank , List<T>&, ListNodePosi<T>, Rank );
    void mergeSort( ListNodePosi<T>&, Rank );
    void selectionSort( ListNodePosi<T>, Rank );
    void insertionSort( ListNodePosi<T>, Rank );
  public:
    // cons & dest
    List(){ init(); }
    List( const List<T>& L );
    List( const List<T>& L, Rank r, Rank n );
    List( ListNodePosi<T> p, Rank n);
    ~List();
    // facility
    Rank size() const { return _size; }
    bool empty() const { return _size <= 0; }
    ListNodePosi<T> operator[]( Rank r ) const;
    ListNodePosi<T> first() const { return head->next; }
    ListNodePosi<T> last() const { return tail->prev; }
    bool isValid(ListNodePosi<T> p) { return p && (p != head) && (p != tail); }
    // getter
    ListNodePosi<T> find( const T& e ) const
    { return find(e, _size, tail); }
    ListNodePosi<T> find( const T& e, Rank n, ListNodePosi<T> p ) const;
    ListNodePosi<T> search( const T& e ) const
    { return search(e, _size, tail); }
    ListNodePosi<T> search( const T& e, Rank n, ListNodePosi<T> p) const;
    ListNodePosi<T> takeMax()
    { return takeMax(head->next, _size); }
    ListNodePosi<T> takeMax( ListNodePosi<T> p, Rank n );
    // listnode manip
    ListNodePosi<T> insertAsFirst( const T& e );
    ListNodePosi<T> insertAsLast( const T& e );
    ListNodePosi<T> insert( ListNodePosi<T> p, const T& e );
    ListNodePosi<T> insert( const T& e, ListNodePosi<T> p );
    T remove( ListNodePosi<T> p );
    // list manip
    void merge( List<T>& L) 
    { merge ( head->next, _size, L, L.head->next, L._size); }
    void sort( ListNodePosi<T>, Rank );
    void sort(){ return sort( first(), _size ); }
    Rank deduplicate();
    Rank uniquify();
    void reverse();
    // traverse
    void traverse( void(* )( T& ));
    template <typename VST>
      void traverse( VST& );

};
#include "list_imple.h"
#include <boost/core/demangle.hpp>
template <typename T>
std::ostream& operator<<(std::ostream& ostr, const List<T>& L)
{
  int count = 0;
  ostr << boost::core::demangle( typeid(L).name() ) << "\tSize:\t" << L.size() << "\n{\n";
  for( ListNodePosi<T> p = L.first(); count < L.size() ; p = p->next )
  {
    if ( !p->data )break;
    ostr << p->data << "\t";
    if ((++count) % 10 == 0)
    ostr << "\n";
  }
  ostr << "}" << std::endl;
  return ostr;
}
#endif // !__list__
