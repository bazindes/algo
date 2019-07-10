/*
  PathSum_112.cpp
  Created by: baz
  Date: 2019-07-10 16:52
*/

/**
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */

#include "../../ds/tree/BinaryTree.cpp"
#include <iostream>

using namespace std;
using namespace BinaryTree;

bool cal(TreeNode *node, int cur, int sum){
  if(node == nullptr) return sum == cur;
  return cal(node -> left, cur + node->val, sum) || cal(node -> right, cur + node->val, sum);
}

bool hasPathSum(TreeNode *root, int sum) {
  return cal(root, 0, sum);
}

int main(){

  return 0;
}