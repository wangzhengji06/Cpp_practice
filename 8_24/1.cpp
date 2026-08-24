#include <queue>
#include <vector>

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
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> result;
    if (root == nullptr) {
      return result;
    }
    queue<TreeNode *> container;
    container.push(root);
    while (!container.empty()) {
      int count = container.size();
      double sum = 0;
      for (int i = 0; i < count; ++i) {
        TreeNode *first = container.front();
        container.pop();
        sum += (first->val);
        if (first->left != nullptr) {
          container.push(first->left);
        }
        if (first->right != nullptr) {
          container.push(first->right);
        }
      }
      result.push_back(static_cast<double>(sum) / count);
    }
    return result;
  }
};
