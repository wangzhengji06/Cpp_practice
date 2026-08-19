#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *arg_left, TreeNode *arg_right)
      : val(x), left(arg_left), right(arg_right) {}
};

void preorder(TreeNode *root, std::vector<int> arr) {
  if (root == nullptr) {
    return;
  }
  arr.push_back(root->val);
  preorder(root->left, arr);
  preorder(root->right, arr);
}

std::vector<int> preorderTraversal(TreeNode *root) {
  std::vector<int> arr;
  preorder(root, arr);
  return arr;
}
