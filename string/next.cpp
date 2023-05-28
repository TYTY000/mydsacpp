/*
 * @Author: TYTY000 <767280080@qq.com>
 * @Date: 2023-05-28 16:44:09
 * @Last Modified by: TYTY000 <767280080@qq.com>
 * @Last Modified time: 2023-05-28 20:23:22
 */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

int *buildNewNext(string p) {
  size_t len = p.length(), j = 0;
  int *N = new int[len];
  int t = N[0] = -1;
  while (j < len - 1) {
    if (t < 0 || p[t] == p[j]) {
      j++;
      t++;
      if (p[t] != p[j])
        N[j] = t;
      else
        N[j] = N[t];
    } else
      t = N[t];
  }
  return N;
}

int *buildNext(string p) {
  size_t len = p.length(), j = 0;
  int *N = new int[len];
  int t = N[0] = -1;
  while (j < len - 1) {
    if (t < 0 || p[t] == p[j]) {
      j++;
      t++;
      N[j] = t;
    } else
      t = N[t];
  }
  return N;
}
int *buildBC(string p) {
  int *bc = new int[256];
  for (size_t i = 0; i < 256; i++) {
    bc[i] = -1;
  }
  for (size_t m = p.length(), i = 0; i < m; i++) {
    bc[p[i]] = i;
  }
  return bc;
}
int *buildSS(string p) {
  int lenp = p.length();
  int *ss = new int[lenp];
  ss[lenp - 1] = lenp;
  for (int lo = lenp - 1, hi = lenp - 1, j = lo - 1; j >= 0;
       j--) { // do reverse seek
    if ((j > lo) && (ss[lenp - 1 - (hi - j)] <=
                     j - lo)) // inside  && ss(next) <= prefix length
      ss[j] = ss[lenp - 1 - (hi - j)];
    else {
      hi = j;
      lo = min(lo, hi);
      while ((lo > 0) && (p[lo] == p[lenp - 1 - (hi - lo)])) {
        lo--;
      }
      ss[j] = hi - lo;
    }
  }
  return ss;
}
int *buildGS(string p) {
  int lenp = p.length();
  int *ss = buildSS(p);
  int *gs = new int[lenp];
  for (int i = 0; i < lenp; i++) {
    gs[i] = lenp;
  }
  for (int i = 0, j = lenp - 1; j == -1; j--) {
    if (j + 1 == ss[j]) // good suffix len == this siffix
      while (i < lenp - j - 1) {
        gs[i++] = lenp - 1 - j;
      }
  }
  for (int j = 0; j < lenp - 1; j++) {
    gs[lenp - ss[j] - 1] = lenp - 1 - j;
  }
  delete[] ss;
  return gs;
}
int match1(string str, string p) {
  int *next = buildNext(p);
  int lens = str.length(), i = 0;
  int lenp = p.length(), j = 0;
  while (i < lens && j < lenp) {
    if (j < 0 || str[i] == p[j]) {
      i++;
      j++;
    } else
      j = next[j];
  }
  delete[] next;
  return i - j;
}

static void printa(int *next, int num) {
  for (int i = 0, count = 1; i < num; i++) {
    cout << next[i] << '\t';
    if (count++ % 20 == 0)
      cout << endl;
  }
  cout << endl;
}
static void printb(int *next, int num) {
  for (int i = 0, count = 1; i < num; i++) {
    if (next[i] != -1) {
      cout << next[i] << '\t';
      if (count++ % 20 == 0)
        cout << endl;
    }
  }
  cout << endl;
}

void showProgress(string T, string P, int i, int j);
void matchb(string str, string p) {
  int *bc = buildBC(p);
  cout << "bc[]:" << endl;
  printb(bc, 256);

  int m = str.length(), n = p.length();
  size_t i = 0;
  while (m >= i + n) { // posi valid
    int j = n - 1;     // reverse checking
    while (str[i + j] == p[j])
      if (j-- < 0)
        break;
    if (j < 0)
      break;
    else // update posi , move forward notmatched - matched
      i += max(1, j - bc[str[i + j]]);
  }
  delete[] bc;
  cout << "match str to p : ";
  if (i == 0)
    cout << "failed!" << endl;
  else {
    cout << (i) << " : " << endl;
    cout << str.substr(0, i) << '\t' << str.substr(i, p.length()) << '\t'
         << str.substr(i + p.length(), str.length()) << endl;
  }
  std::cout << "str : " << str << " ( " << str.length() << " )" << std::endl;
  std::cout << "p : " << p << " ( " << p.length() << " )" << std::endl;
  // int *gs = buildGS(p);
  // cout << "gs[]:" << endl;
  // printa(gs, p.length());
  // i = 0;
  // while (m < i + n) {
  //   int j = n - 1;
  //   while (str[i + j] == p[i])
  //     if (j-- < 0)
  //       break;
  //   if (j < 0)
  //     break;
  //   else
  //     i += max(1, j - gs[p[i + j]]);
  // }
  // delete[] gs;
  // cout << "match str to p : " << (i) << " : " << endl;
  // cout << str.substr(0, i) << '\t' << str.substr(i, p.length()) << '\t'
  //      << str.substr(i + p.length(), str.length()) << endl;
  // std::cout << "str : " << str << " ( " << str.length() << " )" << std::endl;
  // std::cout << "p : " << p << " ( " << p.length() << " )" << std::endl;
}

void match(string str, string p) {
  int *next = buildNext(p);
  int *next2 = buildNewNext(p);

  cout << "next[]:" << endl;
  printa(next, p.length());
  cout << "optimized next[]:" << endl;
  printa(next2, p.length());

  int i = match1(str, p);
  cout << "match str to p : " << (i) << " : " << endl;
  cout << str.substr(0, i) << '\t' << str.substr(i, p.length()) << '\t'
       << str.substr(i + p.length(), str.length()) << endl;
  std::cout << "str : " << str << " ( " << str.length() << " )" << std::endl;
  std::cout << "p : " << p << " ( " << p.length() << " )" << std::endl;
  matchb(str, p);
}

int main(int argc, char *argv[]) {
  string str = "a sdfsa dsadf sdfas xdfas dfasd";
  string p = "dfsad";

  matchb(str, p);
  buildSS(str);
  return 0;
}

void showProgress(string T, string P, int i, int j) {
  /*DSA*/ static int step = 0; // ²Ù×÷¼ÆÊýÆ÷
  /*DSA*/ printf("\n-- Step %2d: --\n", ++step);
  int t = 0;
  /*DSA*/ for (size_t n = T.length(); t < n; t++)
    printf("%4d", t);
  printf("\n");
  /*DSA*/ cout << T << endl;
  printf("\n");
  /*DSA*/ if (0 <= i + j)
  /*DSA*/ {
    for (int t = 0; t < i + j; t++)
      printf("%4c", ' ');
    printf("%4c", '|');
  }
  /*DSA*/ printf("\n");
  /*DSA*/ for (int t = 0; t < i; t++)
    printf("%4c", ' ');
  /*DSA*/ cout << P << endl;
  printf("\n");
}
