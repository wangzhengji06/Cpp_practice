#include <vector>

using namespace std;

int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
  int n = static_cast<int>(customers.size());

  int baseSatisfied = 0;
  int windowExtra = 0;
  int maxExtra = 0;

  for (int i = 0; i < n; ++i) {
    if (grumpy[i] == 0) {
      baseSatisfied += customers[i];
    }
    if (grumpy[i] == 1) {
      windowExtra += customers[i];
    }
    if (i >= minutes && grumpy[i - minutes] == 1) {
      windowExtra -= customers[i - minutes];
    }
    maxExtra = max(maxExtra, windowExtra);
  }
  return baseSatisfied + maxExtra;
}
