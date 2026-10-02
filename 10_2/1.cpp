#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> inventoryManagement(vector<int> &stock, int cnt) {
    if (cnt == 0) {
      return {};
    }
    priority_queue<int> pq;
    for (int num : stock) {
      if (pq.size() < cnt) {
        pq.push(num);
      } else if (pq.top() > num) {
        pq.pop();
        pq.push(num);
      }
    }
    vector<int> result;
    while (!pq.empty()) {
      result.push_back(pq.top());
      pq.pop();
    }
    return result;
  }
};
