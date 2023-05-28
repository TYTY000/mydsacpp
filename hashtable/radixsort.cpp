
#include "../vector/vector.h"
#include <algorithm>
#include <iostream>
using namespace std;

#define dice(X) (rand() % (X))
void generate(Vector<int> &v, int bound, int size) {
  while (size--) {
    v.insert(dice(bound));
  }
}

Vector<int> countingSort(Vector<int> &v, int max, int base) {
  Vector<int> output = v;
  int size = static_cast<int>(v.size());
  const int bucket = base;
  int count[bucket];
  for (int i = 0; i < bucket; ++i) {
    count[i] = 0;
  } // init
  for (int i = 0; i < size; i++) {
    count[(v[i] / base) % bucket]++;
  } // hashcode buckets
  for (int i = 1; i < bucket; i++) {
    count[i] += count[i - 1];
  } // cumulate buckets, monotonic increasing.....
  for (int i = size - 1; i >= 0; i--) {
    output[count[(v[i] / base) % bucket] - 1] = v[i];
    count[(v[i] / base) % bucket]--;
  } // mapping to corresponding position in vector...
  return output;
}

int getMax(Vector<int> &v) {
  int max = v[0];
  int size = v.size();
  for (int i = 1; i < size - 1; i++)
    if (v[i] > max)
      max = v[i];
  return max;
}

void radix_sort(Vector<int> &v) {
  // radix sort need to know max elem, for deciding loop iteration.
  int max = getMax(v);
  for (int base = 1; max / base > 0; base *= 10) {
    v = countingSort(v, max, base);
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
  radix_sort(v);
  cout << v;
}
