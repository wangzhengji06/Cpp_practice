// Problem: This question feels like deep search. The only problem here is how
// do I maintain the vector?

// Initial thought: I just do a normal deep search, and append node to vector
// when iterating, if it fails then I pop that element out, and reduce the
// currentSum.

// Observation: When I am implmenting it, I realize that it is kind of hard to
// pop... Nope not hard
// Investigation: The key idea seems to be, every time I enter into a dfs stack,
// I need to keep the path exactly as is. Which means I only need to pop the
// thing I added in the current stack

// Determination: Each dfs stack call owns exactly one push/pop.

// Reflection: See investigation

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
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (!root) {
      return results;
    }
    vector<int> path;
    deepSearch(root, path, 0, targetSum);
    return results;
  }

private:
  vector<vector<int>> results;
  void deepSearch(TreeNode *root, vector<int> &path, int currentSum,
                  int targetSum) {
    if (root->left == nullptr && root->right == nullptr) {
      path.push_back(root->val);
      currentSum += root->val;
      if (currentSum == targetSum) {
        results.push_back(path);
      }
      path.pop_back();
      return;
    }
    path.push_back(root->val);
    currentSum += root->val;
    if (root->left) {
      deepSearch(root->left, path, currentSum, targetSum);
    }
    if (root->right) {
      deepSearch(root->right, path, currentSum, targetSum);
    }
    path.pop_back();
  }
};
