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
  std::vector<int> postorderTraversal(TreeNode *root) {
    vector<int> arr;
    postorder(root, arr);
    return arr;
  }

private:
  void postorder(TreeNode *root, std::vector<int> &arr) {
    if (root != nullptr) {
      stack<TreeNode *> container;
      container.push(root);
      while (!container.empty()) {
        TreeNode *curr = container.top();
        // does it have left child, and left child hasn't procesed yet?
        if (curr->left != nullptr && root != curr->left &&
            root != curr->right) {
          container.push(curr->left);
        }
        // does it have right child, and right child hasn't processed yet?
        else if (curr->right != nullptr && root != curr->right) {
          container.push(curr->right);
        }
        // no left child, right hild or both has been processed
        else {
          arr.push_back(curr->val);
          root = container.top();
          container.pop();
        }
      }
    }
  }
};
