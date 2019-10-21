/*
  SymmetricTree_101.cpp
  Created by: baz
  Date: 2019-06-03 16:37
*/

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric
around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3


But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3


Note:
Bonus points if you could solve it both recursively and iteratively.
*/

#include "BinaryTree.h"

using namespace BinaryTree;

bool helper(TreeNode *left, TreeNode *right);

bool isSymmetric(TreeNode *root) {
  if(root == nullptr) return true;
  return helper(root->left, root->right);
}

bool helper(TreeNode *left, TreeNode *right){
  if(left == nullptr && right == nullptr) return true;
  if(left == nullptr || right == nullptr) return false;
  return (left->val == right->val) && helper(left->left, right->right) && helper(left->right, right->left);
}

// int main(){
//   int n1[] = {1,2,2,3,4,4,3};
//   TreeNode* t1 = buildBT(n1, 7, 0);
//   printTree(inOrderTraversal, t1);
//   // cout << isSymmetric(t1) << endl;
//   int n2[] = {1,2,2,0,3,0,3};
//   TreeNode* t2 = buildBT(n2, 7, 0);
//   printTree(inOrderTraversal, t2);
//   // cout << isSymmetric(t2) << endl;
// }