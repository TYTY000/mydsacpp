#include "../vector/vector.h"
#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

int cnt = 78498;
std::string file = "./prime-1000000.txt";

void readline(int n, Vector<int> &v, string file) {
  ifstream ifs;
  ifs.open(file);
  if (ifs.fail()) {
    cout << "Error: " << file << endl;
    exit(-1);
  }
  string line;
  for (int count = 0; count < n; count++) {
    getline(ifs, line);
    v.insert(stoi(line));
  }
}

static int binSearch(Vector<int> &v, int n, int c) {
  int lo = 0, hi = n;
  int mi = 0;
  while (hi > lo) {
    mi = (lo + hi) >> 1;
    (c < v[mi]) ? hi = mi : lo = mi + 1;
  }
  return v[lo - 1];
}

/*
 * c -> upper bound for prime
 * n -> lines of file
 * file -> filedir
 * return the value of biggest integer <= c
 */
int PrimeNLT(Vector<int> &v, int n, int c) { return binSearch(v, n, c); }

int main(int argc, char *argv[]) {
  Vector<int> v = Vector<int>(78498, 0);
  readline(cnt, v, file);
  while (true) {
    string prompt = "the number u choose is : ";
    string num;
    cout << prompt;
    getline(cin, num);
    int u = stoi(num);
    int prime = PrimeNLT(v, cnt, u);
    std::cout << prime << std::endl;
  }
  return 0;
}
