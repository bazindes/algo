/*
  MinimumDepthOfBinaryTree_111.cpp
  Created by: baz
  Date: 2019-07-10 16:49
*/

/**
 * Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root
node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
 */

#include "../../ds/tree/BinaryTree.cpp"
#include <stdlib.h>

using namespace BinaryTree;
using namespace std;

// O(n)
int minDepth(TreeNode *root) {
  if (!root)
    return 0;
  if (root->left == nullptr && root->right != nullptr)
    return 1 + minDepth(root->right);
  else if (root->left != nullptr && root->right == nullptr)
    return 1 + minDepth(root->left);
  else
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}