// Problem:
// I need to find a way to describe how to seperate the two trees. I also was
// wondering if I can calculate the sum in one go instead of calucalting one
// tree for twice.

// Initial Reasoning:
// every line has a parent and a child. I only need to identify the line that
// relationship happens. Then I can do something like result *
// calculate_sum(node ->left/right).

// Investigation:
// Observation: I can iterate over the whole tree using whatever method, and I
// can always determine the connection from it to its child.
// Hypothesis: If I know the sum of the entire tree and the sum of the child's
// subtree, I can calculate both partition sums without physically separating
// the tree.
// Evidence: Cutting an edge gives a subtree with sum s and a complementary tree
// with sum total - s.

// Determination: Use postorder traversal to compute every subtree sum once.
// Then evaluate the product for each candidate subtree.

// Reflection: The essential insight is that every edge cut corresponds to a
// subtree and its complement. Once the total tree sum is known, only the
// subtree sum is needed to evaluate a cut.
// I initially tried to avoid traversing the tree twice, but this led to
// repeated subtree calculations. Two complete linear traversals are preferable
// to repeatedly traversing overlapping subtrees. Postorder traversal is
// appropriate because computing a node's subtree sum requires the sums of its
// children.
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
  int maxProduct(TreeNode *root) {
    long long sum = calculateSum(root);
    long long res = maxProductHelper(root, sum);
    return static_cast<int>(max_num % 1'000'000'007LL);
  }

  long long maxProductHelper(TreeNode *node, long long total) {
    if (node == nullptr) {
      return static_cast<long long>(0);
    }
    long long left = maxProductHelper(node->left, total);
    long long right = maxProductHelper(node->right, total);
    long long val = left + right + node->val;
    max_num = max(max_num, (total - val) * val);
    return left + right + node->val;
  }

  long long calculateSum(TreeNode *node) {
    if (node == nullptr) {
      return static_cast<long long>(0);
    }
    long long left = calculateSum(node->left);
    long long right = calculateSum(node->right);
    return left + right + node->val;
  };

private:
  long long max_num = 0;
};
