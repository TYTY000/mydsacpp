#ifndef __list_sort__
#define __list_sort__

#include <cstdlib>
template <typename T>
void List<T>::sort(ListNodePosi<T> p, Rank n)
{
  switch ( rand() % 2 ) {
    case 1:   std::cout << "insertionSort" << std::endl; insertionSort( p, n ); break;
    case 0:   std::cout << "selectionSort" << std::endl; selectionSort( p, n ); break;
    default:  break;
  }
}

#endif // !__list_sort__
