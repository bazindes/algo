/*
  SameTree_100.cpp
  Created by: baz
  Date: 2019-06-03 16:23
*/

/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and
the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
*/

#include "BinaryTree.h"

using namespace std;
using namespace BinaryTree;

bool isSameTree(TreeNode *p, TreeNode *q) {
  if (p == nullptr && q == nullptr)
    return true;
  if (p == nullptr || q == nullptr)
    return false;
  return (p->val == q->val) && isSameTree(p->left, q->left) &&
         isSameTree(p->right, q->right);
}

// int main() {
//   int n1[] = {1, 2, 3};
//   TreeNode* t1 = buildBT(n1, 3, 0);
//   TreeNode* t2 = buildBT(n1, 3, 0);
//   // cout << isSameTree(t1, t2) << endl;
//   int n2[] = {1, 2};
//   int n3[] = {1, 0, 2};
//   TreeNode* t3 = buildBT(n2, 3, 0);
//   TreeNode* t4 = buildBT(n3, 3, 0);
//   // cout << isSameTree(t3, t4) << endl;
// }