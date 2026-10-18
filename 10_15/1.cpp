// Problem: I need to find a way to insert the given TreeNode into the
// Binary Search Tree. Binary search satisfies: node -> left -> val <
// node -> val && node -> right -> val > node -> val Initial Resoning:
// This should be recursion useing in order method. Because in order
// method recreate an ordered list.  How should the node be inserted?
// it should go all the way until some element is larger than it, then
// it append to the left. BUt what if that node already has a left
// node? then I go to itst left node and go on to its right node.
// What if it further as a right node? then I go to the right node and
// append to its left node. I feel like there should be a smater way.
// That means I need to do one recursion to get the maximum node. Then
// I need to implmement a loop logic. Is there edge case? I dont think
// so.
//
// Investigation: Observation:
// I tried to find the smallest node that is larger than val, and it actually
// works. But I am not  making use of the binary search tree property itself.
// hypothesis: My original thought is not intuitively most leading
// Determination: I will use Binary search tree property and conduct a simple
// one.
// Reflection:  I found myself to early to think about this tree as a ordered
// sequence. The tree itself is already a more flexible data structure compared
// to vector, thinking in that way is definitely dangerous.
//

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
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) {
      return new TreeNode(val);
    }

    if (val < root->val) {
      root->left = insertIntoBST(root->left, val);
    } else {
      root->right = insertIntoBST(root->right, val);
    }

    return root;
  }
};
