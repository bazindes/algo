/*
  BinaryTreeLevelOrderTraversal_II_107.cpp
  Created by: baz
  Date: 2019-06-11 16:28
*/

/*
Given a binary tree, return the bottom-up level order traversal of its nodes'
values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
 */

#include "BinaryTree.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using namespace BinaryTree;

// BFS O(n)
vector<vector<int>> levelOrderBottom(TreeNode *root) {
  vector<vector<int>> ans;
  if (root) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      vector<int> temp;
      while (size-- > 0) {
        TreeNode *cur = q.front();
        q.pop();
        temp.push_back(cur->val);
        if (cur->left)
          q.push(cur->left);
        if (cur->right)
          q.push(cur->right);
      }
      ans.insert(ans.begin(), temp);
    }
  }

  return ans;
}

// int main() {
//   int *nums[] = {new int(3), new int(9),  new int(20), nullptr,
//                  nullptr,    new int(15), new int(7)};
//   TreeNode *t1 = buildBT(nums, 7, 0);
//   printTree(inOrderTraversal, t1);
//   vector<vector<int>> ans = levelOrderBottom(t1);
//   // cout << ans;
//   return 0;
// }
