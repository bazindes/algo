/*
  BinaryTree.cpp
  Created by: baz
  Date: 2019-04-09 17:23
*/

#include "BinaryTree.h"
#include <iostream>
#include <functional>

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

BinaryTree::TreeNode *BinaryTree::buildBT(int **nums, int n, int i){
  if (i > n - 1 || nums[i] == nullptr)
    return nullptr;
  TreeNode *cur = new TreeNode(*nums[i]);
  cur->left = buildBT(nums, n, 2 * i + 1);
  cur->right = buildBT(nums, n, 2 * i + 2);
  return cur;
}

void BinaryTree::inOrderTraversal(TreeNode *root, void (*func)(BinaryTree::TreeNode *)) {
  if (!root)
    return;
  inOrderTraversal(root->left, func);
  func(root);
  inOrderTraversal(root->right, func);
}

void BinaryTree::preOrderTraversal(TreeNode *root, void (*func)(BinaryTree::TreeNode *)) {
  if (!root)
    return;
  func(root);
  preOrderTraversal(root->left, func);
  preOrderTraversal(root->right, func);
}

void BinaryTree::postOrderTraversal(TreeNode *root, void (*func)(BinaryTree::TreeNode *)) {
  if (!root)
    return;
  postOrderTraversal(root->left, func);
  postOrderTraversal(root->right, func);
  func(root);
}
