#include <algorithm>
#include <limits>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int maxPathSum(TreeNode *root) {
    maxSum = numeric_limits<int>::lowest();
    maxContribute(root);
    return maxSum;
  }

  int maxContribute(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    int leftGain = max(maxContribute(node->left), 0);
    int rightGain = max(maxContribute(node->right), 0);
    int candidate = node->val + leftGain + rightGain;
    maxSum = max(maxSum, candidate);
    return node->val + max(leftGain, rightGain);
  }

private:
  int maxSum;
};
