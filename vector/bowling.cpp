#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using Rank = unsigned int;

void generateBowlingPins(vector<int> &v, Rank bound, int nums);
void bestFit(vector<int> &v, Rank index, vector<int> &score);
void getBestShot(vector<int> &v, vector<int> &score);

int main(int argc, char *argv[]) {

  if (3 > argc) {
    printf("Usage: %s <pin score upperbound> <pins>\a\a\n", argv[0]);
    return 1;
  }

  srand((unsigned int)time(NULL));
  Rank bound = atoi(argv[1]);
  int nums = atoi(argv[2]);
  vector<int> v;
  vector<int> score(nums,0);

  generateBowlingPins(v, bound, nums);
  getBestShot(v, score);
  return 0;
}

#include <boost/core/demangle.hpp>
template <typename T>
std::ostream &operator<<(std::ostream &os, const vector<T> &V) {
  int count = 0;
  os << boost::core::demangle(typeid(V).name()) << "\tSize:\t" << V.size()
     << "\n{\n";
  for (Rank i = 0; count < V.size(); i++) {
    os << V[i] << "\t";
    if ((++count) % 10 == 0)
      os << "\n";
  }
  os << "}\n" << std::endl;
  return os;
}

void generateBowlingPins(vector<int> &v, Rank bound, int nums) {
  while (nums-- > 0) {
    if (rand() % 4)
      v.insert(v.begin(), rand() % (2 * bound));
    else
      v.insert(v.begin(), -(rand() % (2 * bound)));
  }
  std::cout << "\ngenerated pins :" << std::endl;
  std::cout << v << std::endl;
}

void bestFit(vector<int> &v, Rank index, vector<int> &score) {
  if (index == v.size() - 1)
    score[index] = max(0, v[index]);
  else if (index == v.size() - 2)
    score[index] =
        max(v[index], max(v[index] * v[index + 1], score[index + 1]));
  else
    score[index] =
        max(score[index + 1], max(score[index + 1] + v[index],
                                  score[index + 2] + v[index] * v[index + 1]));
}

void getBestShot(vector<int> &v, vector<int> &score) {
  for (Rank i = v.size() -1; i > 0; i--)
  {
    bestFit(v, i, score);
  }
    bestFit(v, 0, score);
  auto highestScore = max_element(score.begin(),score.end());
  std::cout << "highestScore is : " << *highestScore << std::endl;

}
