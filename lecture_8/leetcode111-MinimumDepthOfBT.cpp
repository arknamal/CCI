/*
111. Minimum Depth of Binary Tree
Easy

Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 2

Example 2:
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5

Constraints:
  The number of nodes in the tree is in the range [0, 105].
  -1000 <= Node.val <= 1000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// intuitive solution:
class Solution {
public:
  int minDepth(TreeNode* root) {
    if(root)
      if(!root->left && !root->right)
        return 1;
      else if(!root->left)
        return minDepth(root->right) + 1;
      else if(!root->right)
        return minDepth(root->left) + 1;
      else
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    else
      return 0;
  }
};

// second solution - using queue (find the first leaf in level-order traversal and exit immediately):
class Solution {
  bool isLeaf(TreeNode* root) {
    return !(root->left || root->right);
  }

  int closestLeaf(queue<TreeNode*>& Q) {
    int depth = 0;
    while(!Q.empty()) {
      int size = Q.size();
      for(int i = 0; i < size; i++) {
        TreeNode* N = Q.front();
        if(isLeaf(N))
          return depth;
        Q.pop();
        TreeNode* L = N->left;
        TreeNode* R = N->right;
        if(L)
          Q.push(L);
        if(R)
          Q.push(R);
      }
      depth++;
    }
    return 0;
  }

public:
  int minDepth(TreeNode* root) {
    if(root) {
      queue<TreeNode*> Q;
      Q.push(root);
      return closestLeaf(Q) + 1;
    }
    else
      return 0;
  }
};