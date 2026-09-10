struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// Starting from the root, use targetSum - currenct value
// when it's leaf, check it targetSum is 0
// When it's not leaf, check if left and right child satisfies

class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    targetSum -= root->val;
    if (root->left == nullptr && root->right == nullptr) {
      return targetSum == 0;
    } else {
      return hasPathSum(root->left, targetSum) ||
             hasPathSum(root->right, targetSum);
    }
  }
};
