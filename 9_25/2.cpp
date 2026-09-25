#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();

    if (n == 0)
      return "";

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int start = 0;
    int maxLen = 1;

    for (int len = 1; len <= n; ++len) {
      for (int i = 0; i + len <= n; ++i) {
        int j = i + len - 1;

        if (s[i] == s[j] && (len <= 2 || dp[i + 1][j - 1])) {

          dp[i][j] = true;

          if (len > maxLen) {
            start = i;
            maxLen = len;
          }
        }
      }
    }

    return s.substr(start, maxLen);
  }
};
