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
  std::vector<int> inorderTraversal(TreeNode *root) {
    vector<int> arr;
    inorder(root, arr);
    return arr;
  }

private:
  void inorder(TreeNode *root, std::vector<int> &arr) {
    if (root != nullptr) {
      stack<TreeNode *> container;
      while (container.size() != 0 || root != nullptr) {
        // I need to check if child exists, and if it does exists, I want the
        // left node all the way
        if (root != nullptr) {
          container.push(root);
          root = root->left;
        }
        // Then I need to pop from container, and check the right child and do
        // the left node all the way
        else {
          root = container.top();
          container.pop();
          arr.push_back(root->val);
          root = root->right;
        }
      }
    }
  }
};
