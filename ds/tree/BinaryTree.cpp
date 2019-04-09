/*
  BinaryTree.cpp
  Created by: baz
  Date: 2019-04-09 17:23
*/

#include "BinaryTree.h"
#include <iostream>

BinaryTree::TreeNode::TreeNode():val(0), left(nullptr), right(nullptr) {}
BinaryTree::TreeNode::TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
BinaryTree::TreeNode::~TreeNode(){}

void BinaryTree::inOrderTraversal(TreeNode *root) {
  if(!root) return;
  inOrderTraversal(root -> left);
  std::cout << root -> val << " | ";
  inOrderTraversal(root -> right);
}
void BinaryTree::preOrderTraversal(TreeNode *root) {
  if(!root) return;
  std::cout << root -> val << " | ";
  preOrderTraversal(root -> left);
  preOrderTraversal(root -> right);
}
void BinaryTree::postOrderTraversal(TreeNode *root) {
  if(!root) return;
  postOrderTraversal(root -> left);
  postOrderTraversal(root -> right);
  std::cout << root -> val << " | ";
}