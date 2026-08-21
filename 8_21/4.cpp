#include <stack>
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
  std::vector<int> preorderTraversal(TreeNode *root) {
    vector<int> arr;
    preorder(root, arr);
    return arr;
  }

private:
  void preorder(TreeNode *root, std::vector<int> &arr) {
    if (root != nullptr) {
      stack<TreeNode *> container;
      container.push(root);
      while (container.size() != 0) {
        TreeNode *top = container.top();
        container.pop();
        arr.push_back(top->val);
        if (top->right != nullptr) {
          container.push(top->right);
        }
        if (top->left != nullptr) {
          container.push(top->left);
        }
      }
    }
  }
};
