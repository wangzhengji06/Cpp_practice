#include <queue>
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
  std::vector<int> levelOrder(TreeNode *root) {
    vector<int> arr;
    lorder(root, arr);
    return arr;
  }

private:
  void lorder(TreeNode *root, std::vector<int> &arr) {
    // pop the first node, and append its children to queue
    // if quque is emtpy, stop
    if (root == nullptr) {
      return;
    }
    std::queue<TreeNode *> container;
    container.push(root);
    while (!container.empty()) {
      TreeNode *first = container.front();
      container.pop();
      arr.push_back(first->val);
      if (first->left != nullptr) {
        container.push(first->left);
      }
      if (first->right != nullptr) {
        container.push(first->right);
      }
    }
  }
};
