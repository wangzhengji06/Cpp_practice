#include <algorithm>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};

class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    // I want to return the minimal Height for that node
    if (root->left == nullptr && root->right == nullptr) {
      return 1;
    } else if (root->left != nullptr && root->right == nullptr) {
      return 1 + minDepth(root->left);
    } else if (root->left == nullptr && root->right != nullptr) {
      return 1 + minDepth(root->right);
    } else {
      return 1 + min(minDepth(root->left), minDepth(root->right));
    }
  }
};
