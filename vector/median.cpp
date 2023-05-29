#include "vector.h"
#include <algorithm>
#include <future>
#include <iostream>
using namespace std;

void vec_init(Vector<int> &v, int n);
void quicksort(Vector<int> &v);
void quicksort(Vector<int> &v, Rank lo, Rank hi);
Rank partition(Vector<int> &v, Rank lo, Rank hi);

int trivialMedian(Vector<int> &v, Rank lo1, Rank n1, Vector<int> &w, Rank lo2,
                  Rank n2) {
  Rank h1 = lo1 + n1;
  Rank h2 = lo2 + n2;
  Vector<int> s;
  while ((lo1 < h1) && (lo2 < h2)) {
    while ((lo1 < h1) && v[lo1] <= w[lo2]) {
      s.insert(v[lo1++]);
    }
    while ((lo2 < h2) && w[lo2] <= v[lo1]) {
      s.insert(w[lo2++]);
    }
  }
  while (lo1 < h1) {
    s.insert(v[lo1++]);
  }
  while (lo2 < h2) {
    s.insert(w[lo2++]);
  }
  return s[(n1 + n2) >> 1];
}
// int median(Vector<int> &v, Rank lo1, Vector<int> &w, Rank lo2, Rank n) {
//   if (n < 3)
//     return trivialMedian(v, lo1, n, w, lo2, n);
//   Rank mi1 = lo1 + n / 2, mi2 = lo2 + (n - 1) / 2;
//   if (v[mi1] < w[mi2])
//     return median(v, mi1, w, lo2, n - mi1 + lo1);
//   else if (v[mi1] > w[mi2])
//     return median(v, lo1, w, mi2, n - mi2 + lo2);
//   else
//     return v[mi1];
// }

/*
 * n = vectorlength
 */
int median(Vector<int> &v, Rank lo1, Rank n1, Vector<int> &w, Rank lo2,
           Rank n2) {
  if (n1 > n2)
    return median(w, lo2, n2, v, lo1, n1); // let w longer than v.
  if (n2 < 6)
    return trivialMedian(v, lo1, n1, w, lo2, n2); // easy brute-force.
  if (2 * n1 < n2)
    return median(v, lo1, n1, w, lo2 + (n2 - n1 - 1) / 2,
                  n1 + 2 - (n2 - n1) % 2); // evenly cut longer vector.
  Rank mi1 = lo1 + n1 / 2, mi2a = lo2 + (n1 - 1) / 2,
       mi2b = lo2 - 1 + n2 - n1 / 2; // 2a is shorter than 2b;
  if (v[mi1] < w[mi2a])
    return median(v, mi1, (n1 + 1) / 2, w, lo2,
                  n2 - n1 / 2); // higher half(v) + lower half(w)
  else if (v[mi1] > w[mi2b])
    return median(v, lo1, n1 / 2 + 1, w, mi2a,
                  n2 - (n1 - 1) / 2); // lower half(v) + mid (w)
  else
    return median(v, lo1, n1, w, mi2a,
                  n2 - (n1 - 1) / 2 * 2); // lower half(v) + middle(w)
}

void quickSelect(Vector<int> &v, Rank k) {
  for (Rank lo = 0, hi = v.size(); lo < hi;) {
    Rank i = lo, j = hi;
    int pivot = v[lo]; // ´óµ¨²Â²â
    while (i < j) {    // Ð¡ÐÄÇóÖ¤£ºO(hi - lo + 1) = O(n)
      do
        j--;
      while ((i < j) && (pivot <= v[j]));
      if (i < j)
        v[i] = v[j];
      do
        i++;
      while ((i < j) && (v[i] <= pivot));
      if (i < j)
        v[j] = v[i];
    }             // assert: quit with i == j or j+1
    v[j] = pivot; // v[0,j) <= v[j] <= v(j, n)
    if (k <= j)
      hi = j; // suffix trimmed
    if (i <= k)
      lo = i; // prefix trimmed
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cout << "Usage : " << argv[0] << " <size of test> <size of test>"
              << std::endl;
    exit(-1);
  }
  Vector<int> v;
  Vector<int> w;
  srand(time(NULL));
  int n1 = atoi(argv[1]);
  int n2 = atoi(argv[2]);
  vec_init(v, n1);
  vec_init(w, n2);
  quicksort(v);
  quicksort(w);
  cout << v;
  cout << w;
  cout << "trivial : " << trivialMedian(v, 0, n1, w, 0, n2) << "\t";
  cout << "median : " << median(v, 0, n1, w, 0, n2) << endl;
  while (!w.empty()) {
    v.insert(w.remove(0));
  }
  quicksort(v);
  cout << v;
  Vector<int> s;
  vec_init(s, n1);
  cout << s;
  Vector<int> S(s);
  quicksort(S);
  for (Rank k = 0; k < n1; k++) {
    // while (A.size() < n1) // create a random vector
    // A.insert(rand() % n1);
    /*DSA*/ // PRINT( A );
    Vector<int> tep(s);
    quickSelect(tep, k); // find k-th element
    /*DSA*/ // PRINT( A ); for ( int i = 0; i < n; i++ ) printf( (i == k) ? "
            // ||||" : " ...." ); printf("\n");
    printf((tep[k] == S[k]) ? "k =%4d OK\t" : "k =%4d Failed\t", k);
  }
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
