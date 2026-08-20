#include <stack>
#include <vector>

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
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> result;
    std::stack<TreeNode *> stk;

    if (root == nullptr) {
      return result;
    }

    stk.push(root);

    while (!stk.empty()) {
      TreeNode *temp = stk.top();
      stk.pop();

      if (temp->right != nullptr) {
        stk.push(temp->right);
      }
      if (temp->left != nullptr) {
        stk.push(temp->left);
      }

      result.push_back(temp->val);
    }
    return result;
  }
};
