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
  std::vector<int> postorderTraversal(TreeNode *root) {
    vector<int> arr;
    postorder(root, arr);
    return arr;
  }

private:
  void postorder(TreeNode *root, std::vector<int> &arr) {
    if (root == nullptr) {
      return;
    }

    postorder(root->left, arr);
    postorder(root->right, arr);
    arr.push_back(root->val);
  }
};
