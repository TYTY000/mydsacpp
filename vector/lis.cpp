
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  string str1 = "CARBONHYDRATE";
  stringstream ss;
  string str;
  int n = str1.length();
  vector<int> dp(n, 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (str1[j] < str1[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  int len = *max_element(dp.begin(), dp.end());
  std::cout << len << std::endl;
  int posi = max_element(dp.begin(), dp.end()) - dp.begin();
  do {
    ss << str1[posi];
    int temp = dp[posi]-1;
    dp[posi] = 0;
    while (dp[--posi]!=temp);
    len--;
  } while (len != 0);
  str = ss.str();
  reverse(str.begin(),str.end());
  std::cout << str << std::endl;
  return 0;
}
