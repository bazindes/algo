/*
  BalancedBinaryTree_110.cpp
  Created by: baz
  Date: 2019-07-10 15:26
*/

/**
 * Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ
by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
 */

#include "../../ds/tree/BinaryTree.cpp"
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace BinaryTree;

int height(TreeNode *node);

bool isBalanced(TreeNode *root) { return height(root) == -1; }

int height(TreeNode *node) {
  if (node == nullptr)
    return 0;
  int l = height(node->left);
  int r = height(node->right);
  if (l == -1 || r == -1)
    return -1;
  if (abs(l - r) > 1)
    return -1;
  return max(l, r) + 1;
}

int main() {
  int *nums[] = {new int(1), new int(2), new int(2), new int(3),
                 nullptr,    nullptr,    new int(3), new int(4),
                 nullptr,    nullptr,    new int(4)};
  // int *nums []= {new int(3), new int(9),  new int(20), nullptr,
  //               nullptr,    new int(15), new int(7)};
  TreeNode *t1 = buildBT(nums, 11, 0);
  printTree(inOrderTraversal, t1);
  cout << height(t1) << endl;
  // cout << isBalanced(t1) << endl;
  return 0;
}