/*
  BinaryTree.cpp
  Created by: baz
  Date: 2019-04-09 17:23
*/

#include "BinaryTree.h"
#include <cmath>
#include <iostream>

BinaryTree::TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {}
BinaryTree::TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
BinaryTree::TreeNode::~TreeNode() {}

BinaryTree::TreeNode *BinaryTree::buildBT(int nums[], int n, int i) {
  if (i > n - 1)
    return nullptr;
  TreeNode *cur = new TreeNode(nums[i]);
  cur->left = buildBT(nums, n, 2 * i + 1);
  cur->right = buildBT(nums, n, 2 * i + 2);
  return cur;
}

void BinaryTree::inOrderTraversal(TreeNode *root) {
  if (!root)
    return;
  inOrderTraversal(root->left);
  std::cout << root->val << " | ";
  inOrderTraversal(root->right);
}

void BinaryTree::preOrderTraversal(TreeNode *root) {
  if (!root)
    return;
  std::cout << root->val << " | ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

void BinaryTree::postOrderTraversal(TreeNode *root) {
  if (!root)
    return;
  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  std::cout << root->val << " | ";
}

void BinaryTree::printTree(void (*func)(TreeNode *), TreeNode *root) {
  std::cout << "| ";
  func(root);
  std::cout << std::endl;
}