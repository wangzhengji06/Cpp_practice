// Problem: I need to run recursion in a step by step way. Which means that, I
// have to stop at a specific recursion state
// Initial Reasoning: Recursion are just stacks. Can I just create a stack to
// preserve everything?
// Investigation: observation:
// add a stack and inserting into it at constructor time indeed works, but it is
// O(n) hypothesis:
// Instead of storing the entire traversal, I only need to preserve the nodes
// necessary to determine the next element.
// evidence:
// Determiniation: Maintain a stack of pending nodes instead of precomputing the
// complete traversal. Push the leftmost path initially, then expand the right
// subtree of each popped node.
// Reflection: 1. I tried to use a pointer to a
// local variable and store it even when go out of function
// 2. hasNext() does not always look at right child, it might check parent child
// 3. Replacing recursion with a stack does not necessarily mean saving every
// node. The essential insight is identifying the minimum execution state needed
// to resume the algorithm.

#include <stack>

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

class BSTIterator {
public:
  BSTIterator(TreeNode *root) { push_left(root); }

  int next() {
    TreeNode *now = s.top();
    s.pop();
    push_left(now->right);
    return now->val;
  }

  bool hasNext() { return !s.empty(); }

private:
  stack<TreeNode *> s;
  void push_left(TreeNode *node) {
    while (node != nullptr) {
      s.push(node);
      node = node->left;
    }
  }
};
