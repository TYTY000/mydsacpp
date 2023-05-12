#ifndef __VECTOR_BASIC__
#define __VECTOR_BASIC__

template <typename T>
void Vector<T>::copyFrom ( const T* A, Rank lo, Rank hi )
{
  _elem = new T[_capacity = 2 * ( hi - lo ) ]; _size = 0;
  while ( hi > lo )
    _elem[_size++] = A[lo++];   
}

template <typename T>
T& Vector<T>::operator[] ( Rank r )
{
  return _elem[r];
}

template <typename T>
const T& Vector<T>::operator[] ( Rank r ) const
{
  return _elem[r];
}

template <typename T>
Vector<T>& Vector<T>::operator= ( const Vector<T>& v )
{
  if ( this != &v ) 
  {
    if( _elem ) delete[] _elem;
    copyFrom (v._elem, 0, v.size() );
  }
  return *this;
}


template <typename T>
void Vector<T>::expand()
{
  if ( _size < _capacity ) return;
  if ( _capacity < DEFAULT_CAPA ) _capacity = DEFAULT_CAPA;
  T* ptr = _elem; _elem = new T[_capacity <<= 1];
  for (Rank i = 0; i < _size; i++)
    _elem[i] = ptr[i];
  delete[] ptr;
}

template <typename T>
void Vector<T>::shrink()
{
  if ( _capacity < DEFAULT_CAPA << 1 ) return;
  if ( _size << 2 > _capacity ) return;
  T* ptr = _elem; _elem = new T[_capacity >>= 1];
  for (Rank i = 0; i < _size; i++)
    _elem[i] = ptr[i];
  delete[] ptr;
}

template <typename T>
Rank Vector<T>::maxItem( Rank lo, Rank hi )
{
  Rank r = hi;
  while ( lo < hi-- ) 
    if ( _elem[hi] > _elem[r] )
      r = hi;
  return r;
}

#endif // !__VECTOR_BASIC__
