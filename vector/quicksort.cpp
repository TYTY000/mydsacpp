#include "vector.h"
#include <algorithm>
#include <future>
#include <iostream>
using namespace std;

void vec_init(Vector<int> &v, int n);
void quicksort(Vector<int> &v);
void quicksort(Vector<int> &v, Rank lo, Rank hi);
Rank partition(Vector<int> &v, Rank lo, Rank hi);

int main(int argc, char *argv[]) {
  if (argc != 2)
    std::cout << "Usage : " << argv[0] << " <size of test>" << std::endl;
  Vector<int> v;
  srand(time(NULL));
  vec_init(v, atoi(argv[1]));
  cout << v;
  quicksort(v);
  cout << v;
  return 0;
}

Rank partition(Vector<int> &v, Rank lo, Rank hi) {
  swap(v[lo], v[lo + rand() % (hi - lo + 1)]);
  auto pivot = v[lo];
  while (lo < hi) {
    while (lo < hi)
      if (pivot < v[hi]) {
        hi--;
      } else {
        v[lo++] = v[hi];
        break;
      }
    while (lo < hi)
      if (pivot > v[lo]) {
        lo++;
      } else {
        v[hi--] = v[lo];
        break;
      }
  }
  v[lo] = pivot;
  return lo;
}

void quicksort(Vector<int> &v, Rank lo, Rank hi) {
  if (hi - lo < 2)
    return;
  Rank mi = partition(v, lo, hi - 1);
  quicksort(v, lo, mi);
  quicksort(v, mi + 1, hi);
}

void quicksort(Vector<int> &v) { return quicksort(v, 0, v.size()); }

void vec_init(Vector<int> &v, int n) {
  while (v.size() < n) {
    v.insert(rand() % (3 * n));
  }
}
