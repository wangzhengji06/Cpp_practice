using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
      return root;
    }

    TreeNode *right = invertTree(root->left);
    TreeNode *left = invertTree(root->right);
    root->right = right;
    root->left = left;
    return root;
  }
};
