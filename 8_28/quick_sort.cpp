#include <random>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &num) {
    quickSort(0, static_cast<int>(num.size()) - 1, num);
    return num;
  }

  void quickSort(int l, int r, vector<int> &num) {
    if (l >= r) {
      return;
    }
    uniform_int_distribution<int> dist(l, r);
    int x = num[dist(gen)];
    auto [a, b] = partition(l, r, x, num);
    quickSort(l, a - 1, num);
    quickSort(b + 1, r, num);
  }

  // parition function that takes left, right, and a pivot value x
  pair<int, int> partition(int l, int r, int target, vector<int> &num) {
    // here a stands for everything < a would be less than num[target]
    // b stands for the right guard
    // When i > b then nothing to see
    int a = l;
    int b = r;
    int i = a;

    while (i <= b) {
      if (num[i] == target) {
        ++i;
      } else if (num[i] < target) {
        swap(i++, a++, num);
      } else {
        swap(i, b--, num);
      }
    }
    return {a, b};
  }

  void swap(int i, int j, vector<int> &num) {
    int temp = num[i];
    num[i] = num[j];
    num[j] = temp;
  }

private:
  mt19937 gen{random_device{}()};
};
