#include <algorithm>
#include <boost/core/demangle.hpp>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> Integers{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
bool try_cut(int length, vector<vector<bool>> &dp, vector<int> &cut);
void trace_subset(vector<int> &cut, vector<vector<bool>> &dp, int length);

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
  vector<vector<bool>> dp(Integers.size() + 1, vector<bool>(length + 1));
  for (int i = 0; i <= Integers.size(); i++) {
    dp[i][0] = true;
  }
  for (int i = 0; i <= length; i++) {
    dp[0][i] = false;
  }
  vector<int> cut;
  cut.push_back(0);
  cout << "Set could form sum of : " << length << "? " << boolalpha
       << try_cut(length, dp, cut) << endl;
  trace_subset(cut, dp, length);
  Integers.erase(Integers.begin());
  cut.erase(cut.begin());

  cout << "Set :\t" << Integers << endl;
  cout << "Subset:\t" << cut << endl;
  // cout << "You can trace back by vector<pair<int,int>> cut." << endl;
  // while (length != 0) {
  //   cout << cut[length] << '\t';
  //   length -= cut[length].first;
  // }
  return 0;
}

bool try_cut(int length, vector<vector<bool>> &dp, vector<int> &cut) {
  for (int i = 1; i <= Integers.size(); i++) {
    for (int j = 1; j <= length; j++) {
      if (j >= Integers[i - 1]) {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - Integers[i - 1]];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[Integers.size()][length];
}

void trace_subset(vector<int> &cut, vector<vector<bool>> &dp, int length) {
  int n = Integers.size();
  if (dp[n][length]) {
    while (n > 0 && length > 0) {
      if (dp[n][length] == dp[n - 1][length]) {
        n--;
      } else {
        cut.push_back(Integers[n - 1]);
        length -= Integers[n - 1];
        n--;
      }
    }
  }
}
