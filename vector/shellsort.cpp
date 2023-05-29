
#include "../fib/fib.h"
#include "vector.h"
#include <iostream>
using namespace std;
#define dice(X) (rand() % (X))
void generate(Vector<int> &v, int bound, int size) {
  while (size--) {
    v.insert(dice(bound));
  }
}
void shell(Vector<int> &v, Rank k) {
  for (int i = 0; i < v.size() - 1; i++) {                     // trav
    for (Rank times = v.size() / k + 1; times != 0; times--) { // bubble loops
      while (i + k < v.size() - 1) {                           // index valid
        if (v[i] > v[i + k])
          swap(v[i], v[i + k]);
        i++;
      }
    }
  }
}

void shellSort(Vector<int> &v) {
  Fib fib(v.size());
  fib.prev();
  while (fib.get() != 0) {
    shell(v, fib.get());
    cout << "k = " << fib.get() << endl;
    cout << v;
    fib.prev();
  }
}

int main(int argc, char *argv[]) {
  if (3 > argc) {
    printf("Usage: %s <number upperbound> <size of test>\a\a\n", argv[0]);
    return 1;
  }
  srand((unsigned int)time(NULL));
  int bound = atoi(argv[1]);
  int size = atoi(argv[2]);
  Vector<int> v;
  generate(v, bound, size);
  cout << v;
  shellSort(v);
  cout << v;
}
