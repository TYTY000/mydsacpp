
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int getLISlength(string str, vector<int> &dp, int n);
string getLISstr(string str, vector<int> &dp, int len);
void getLCS(string str);

int main(int argc, char *argv[]) {
  string str1 = "CARBONHYDRATE";
  string str2 = "EMPATHY";
  getLCS(str1);
  getLCS(str2);
}

int getLISlength(string str, vector<int> &dp, int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (str[j] < str[i])
        dp[i] = max(dp[i], dp[j] + 1);
  int len = *max_element(dp.begin(), dp.end());
  std::cout << len << std::endl;
  return len;
}

string getLISstr(string str, vector<int> &dp, int len) {
  int posi = max_element(dp.begin(), dp.end()) - dp.begin();
  stringstream ss;
  string outstr;
  do {
    ss << str[posi];
    int temp = dp[posi] - 1;
    dp[posi] = 0;
    while (dp[--posi] != temp)
      ;
  } while (--len != 0);
  outstr = ss.str();
  reverse(outstr.begin(), outstr.end());
  std::cout << outstr << std::endl;
  return outstr;
}

void getLCS(string str)
{
  int n = str.length();
  vector<int> dp(n, 1);
  int len = getLISlength(str, dp, n);
  str = getLISstr(str, dp, len);
}
