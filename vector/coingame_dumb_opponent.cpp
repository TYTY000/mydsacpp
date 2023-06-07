#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void best_strategy_for_me(vector<int> v, int i, int j);
void optimum_choice(vector<int> &v, vector<vector<int>> &dp1,
                    vector<vector<int>> &dp2, vector<int> &mychoice, int i,
                    int j);
void generate_coins(vector<int> &v, int bound, int nums);

int main(int argc, char *argv[]) {
  if (3 > argc) {
    printf("Usage: %s <coin score upperbound> <coins>\a\a\n", argv[0]);
    return 1;
  }

  int bound = atoi(argv[1]);
  int nums = atoi(argv[2]);
  srand((unsigned int)time(NULL));
  cout << "generating vector ...." << endl;
  vector<int> v;
  generate_coins(v, bound, nums);
  best_strategy_for_me(v, 0, v.size() - 1);
  return 0;
}

#include <boost/core/demangle.hpp>
template <typename T>
std::ostream &operator<<(std::ostream &os, const vector<T> &V) {
  int count = 0;
  os << boost::core::demangle(typeid(V).name()) << "\tSize:\t" << V.size()
     << "\n{\n";
  for (int i = 0; count < V.size(); i++) {
    os << V[i] << "\t";
    if ((++count) % 10 == 0)
      os << "\n";
  }
  os << "}\n" << std::endl;
  return os;
}

void generate_coins(vector<int> &v, int bound, int nums) {
  while (nums-- > 0) {
    int i = rand() % (2 * bound) + 1;
    v.insert(v.begin(), i);
  }
  std::cout << "\ngenerated coins :" << std::endl;
  std::cout << v << std::endl;
}

int take_coin(vector<int> &v, int i) {
  auto coin = v[i];
  cout << "took coin coin[" << i << "] = " << coin << endl;
  return coin;
}

void best_strategy_for_me(vector<int> v, int i, int j) {
  int myscore = 0, otherscore = 0;
  vector<vector<int>> dpa(j + 1, vector<int>(j + 1));
  vector<vector<int>> dpb(j + 1, vector<int>(j + 1));
  vector<int> mychoice;
  optimum_choice(v, dpa, dpb, mychoice, i, j);
}

void optimum_choice(vector<int> &v, vector<vector<int>> &dp1,
                    vector<vector<int>> &dp2, vector<int> &mychoice, int i,
                    int j) {
  int player = 0;
  vector<int> myscore;
  vector<int> yourscore;
  do {
    if (player == 0) {
      int idx = 0;
      if (dp2[i + 1][j] + v[i] >= dp2[i][j - 1] + v[j]) {
        dp1[i][j] = dp2[i + 1][j] + v[i];
        myscore.insert(myscore.begin(), v[i]);
        idx = i++;
      } else {
        dp1[i][j] = dp2[i][j - 1] + v[j];
        myscore.insert(myscore.begin(), v[j]);
        idx = j--;
      }
      cout << "me ";
      take_coin(v, idx);
      player = 1;
    } else if (player == 1) {
      int idx = 0;
      if (dp1[i + 1][j] < dp1[i][j - 1]) {
        dp2[i][j] = dp1[i + 1][j];
        yourscore.insert(yourscore.begin(), v[i]);
        idx = i++;
      } else {
        dp2[i][j] = dp1[i][j - 1];
        yourscore.insert(yourscore.begin(), v[j]);
        idx = j--;
      }
      cout << "you ";
      take_coin(v, idx);
      player = 0;
    }
  } while (i <= j);
  int myhighest = accumulate(myscore.begin(),myscore.end(),0);
  int yourhighest = accumulate(yourscore.begin(),yourscore.end(),0);
  cout << "my highestScore is : " << myhighest << endl;
  cout << "your highestScore is : " << yourhighest << endl;
}
