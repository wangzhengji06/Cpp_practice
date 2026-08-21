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
  std::vector<int> inorderTraversal(TreeNode *root) {
    vector<int> arr;
    inorder(root, arr);
    return arr;
  }

private:
  void inorder(TreeNode *root, std::vector<int> &arr) {
    if (root == nullptr) {
      return;
    }

    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
  }
};
