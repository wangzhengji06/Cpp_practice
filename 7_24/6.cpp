#include <stack>
#include <vector>

using namespace std;
vector<int> dailyTemperatures(vector<int> &temperatures) {
  int len = temperatures.size();
  if (len == 0) {
    return temperatures;
  }

  stack<int> st;
  vector<int> result(len, 0);

  for (int i = 0; i < len; ++i) {
    while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
      int topIdx = st.top();
      result[topIdx] = i - topIdx;
      st.pop();
    }

    st.push(i);
  }

  return result;
}
