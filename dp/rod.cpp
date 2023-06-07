#include <algorithm>
#include <boost/core/demangle.hpp>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> prices{0, 1, 10, 13, 18, 20, 31, 32};
void try_cut(int length, vector<int> &dp, vector<pair<int, int>> &cut);

std::ostream &operator<<(std::ostream &os, const pair<int, int> &p) {
  os << "<" << p.first << "," << p.second << ">";
  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const vector<T> &V) {
  int count = 0;
  for (int i = 0; count < V.size(); i++) {
    os << V[i] << "\t";
    if ((++count) % 10 == 0)
      os << endl;
  }
  return os;
}

int main(int argc, char *argv[]) {
  if (2 > argc) {
    printf("Usage: %s <rod length>\a\a\n", argv[0]);
    return 1;
  }

  int length = atoi(argv[1]);
  vector<int> dp(length+1);
  vector<pair<int, int>> cut;
  cut.push_back(make_pair(0,0));
  try_cut(length, dp, cut);
  dp.erase(dp.begin());
  cout << dp << endl;
  // cout << cut << endl;
  cout << "You can trace back by vector<pair<int,int>> cut." << endl;
  while (length != 0) {
    cout << cut[length]  << '\t';
    length -= cut[length].first;
  }
  return 0;
}

void try_cut(int length, vector<int> &dp, vector<pair<int, int>> &cut) {
  for (int i = 1; i <= length; i++) {
    int idx, max = -1;
    for (int j = 1; j <= i; j++) {
      if (max < dp[i - j] + prices[j % 8]) {
        max = prices[j] + dp[i - j];
        idx = j;
      }
      dp[i] = max;
    }
    cut.push_back(make_pair(idx, prices[idx]));
  }
}
