#ifndef __VECTOR__
#define __VECTOR__

using Rank = unsigned int;
#define DEFAULT_CAPA 8
#include <iostream> 

template <typename T>
class Vector{
  protected:
    Rank _size; Rank _capacity; T* _elem;
    void copyFrom ( const T* A, Rank lo, Rank hi );
    void expand();
    void shrink();
    void bubbleSort ( Rank lo, Rank hi );
    Rank maxItem ( Rank lo, Rank hi );
    void selectionSort ( Rank lo, Rank hi );
    void merge ( Rank lo, Rank mi, Rank hi );
    void mergeSort ( Rank lo, Rank hi );
    void heapSort ( Rank lo, Rank hi );
    Rank partition ( Rank lo, Rank hi );
    void quickSort ( Rank lo, Rank hi );
    void shellSort ( Rank lo, Rank hi );
  public:
    // cons & dest
    Vector ( Rank c = DEFAULT_CAPA, Rank s = 0, T v = 0 )
    { _elem = new T[_capacity = c]; for ( _size = 0; _size < s; _elem[_size++] = v ); }
    Vector ( const T* A, Rank n ) { copyFrom ( A, 0, n ); }
    Vector ( const T* A, Rank lo, Rank hi ) { copyFrom ( A, lo, hi ); }
    Vector ( const Vector<T>& V ) { copyFrom ( V._elem, 0, V._size ); }
    Vector ( const Vector<T>& V, Rank lo, Rank hi ) { copyFrom ( V._elem, lo, hi ); }
    ~Vector() { delete [] _elem; }
    // manip
    Rank size() const { return _size; }
    bool empty() const { return !_size; }
     Rank find ( const T& e ) const { return find ( e, 0, _size ); }
    Rank find ( const T& e, Rank lo, Rank hi ) const;
    Rank search ( const T& e ) const 
    { return ( 0 >= _size ) ? -1 : search ( e, 0, _size ); }
    Rank search ( const T& e, Rank lo, Rank hi ) const;
    T& operator[] ( Rank r );
    const T& operator[] ( Rank r ) const;
    Vector<T>& operator= ( Vector<T> const& );
    T remove ( Rank r );
    Rank remove ( Rank lo, Rank hi );
    Rank insert ( Rank r, const T& e );
    Rank insert ( const T& e ) { return insert ( _size, e ); }
    void sort ( Rank lo, Rank hi );
    void sort() { sort ( 0, _size ); }
    void unsort ( Rank lo, Rank hi );
    void unsort() { unsort ( 0, _size ); }
    Rank disordered();
    Rank deduplicate();
    Rank uniquify();
    void traverse ( void (* ) ( T& ) );
    template <typename VST> void traverse ( VST& );
}; //Vector

template <typename T> static bool lt( T* a, T* b ) { return lt (*a, *b); }
template <typename T> static bool lt( T& a, T& b ) { return a < b; }
template <typename T> static bool eq( T* a, T* b ) { return eq (*a, *b); }
template <typename T> static bool eq( T& a, T& b ) { return a == b; }

#include <boost/core/demangle.hpp>
template<typename T>
std::ostream& operator<<( std::ostream& os, const Vector<T>& V )
{
  int count = 0;
  os << boost::core::demangle( typeid(V).name() ) << "\tSize:\t" << V.size() << "\n{\n";
  for( Rank i = 0; count < V.size() ; i++ )
  {
    os << V[i] << "\t";
    if ((++count) % 10 == 0)
    os << "\n";
  }
  os << "}\n" << std::endl;
  return os;
}


#include "vector_imple.h"

#endif // !__Vector__
