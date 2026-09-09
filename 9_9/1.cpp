#include <algorithm>

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
  int diameterOfBinaryTree(TreeNode *root) {
    maxDiameter = 0;
    height(root);
    return maxDiameter;
  }

private:
  int maxDiameter = 0;

  int height(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    maxDiameter = max(maxDiameter, leftHeight + rightHeight);

    return max(leftHeight, rightHeight) + 1;
  }
};
