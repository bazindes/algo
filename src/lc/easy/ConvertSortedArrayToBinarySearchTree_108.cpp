/*
  ConvertSortedArrayToBinarySearchTree_108.cpp
  Created by: baz
  Date: 2019-06-11 19:02
*/

/*
Given an array where elements are sorted in ascending order, convert it to a
height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in
which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following
height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
 */

#include "BinaryTree.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace BinaryTree;

TreeNode *helper(vector<int> &nums, int l, int r);

// O(nlogn)
TreeNode *sortedArrayToBST(vector<int> &nums) {
  return helper(nums, 0, nums.size() - 1);
}

TreeNode *helper(vector<int> &nums, int l, int r){
  if(l > r) return nullptr;
  int mid = (l + r) / 2;
  TreeNode *t = new TreeNode(nums[mid]);
  t -> left = helper(nums, l, mid - 1);
  t -> right = helper(nums, mid + 1, r);
  return t;
}

int main(){
  vector<int> v = {-10,-3,0,5,9};
  printTree(inOrderTraversal, sortedArrayToBST(v));
}