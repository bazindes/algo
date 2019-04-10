/*
  BinaryTree.h
  Created by: baz
  Date: 2019-04-09 17:13
*/

#if !defined(BINARY_TREE_H)
#define BINARY_TREE_H

namespace BinaryTree {

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode();
  TreeNode(int x);
  ~TreeNode();
};

TreeNode* buildBT(int nums[], int n, int i);

void printTree(void (*func)(TreeNode *), TreeNode *root);

void inOrderTraversal(TreeNode *root);
void preOrderTraversal(TreeNode *root);
void postOrderTraversal(TreeNode *root);

} // namespace BT

#endif // BINARY_TREE_H
