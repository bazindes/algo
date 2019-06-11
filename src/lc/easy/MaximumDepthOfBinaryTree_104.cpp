/*
  MaximumDepthOfBinaryTree_104.cpp
  Created by: baz
  Date: 2019-06-11 15:54
*/

/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root
node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
 */

#include "../../ds/tree/BinaryTree.cpp"
#include <iostream>
#include <queue>

using namespace std;
using namespace BinaryTree;

// BFS O(n) O(n)
int maxDepth(TreeNode *root) {
  int ans = 0;
  if(root){
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
      int size = q.size();
      while(size -- > 0){
        TreeNode * cur = q.front();
        q.pop();
        if(cur -> left) q.push(cur -> left);
        if(cur -> right) q.push(cur -> right);
      }
      ans ++;
    }
  }
  return ans;
}


// DFS O(n) O(1)
int maxDepth_(TreeNode *root){
  if(root) return 1 + max(maxDepth_(root -> left), maxDepth_(root -> right));
  else return 0;
}

int main() {
  int *n[] = { new int(3), new int(9), new int(20), nullptr, nullptr, new int(15), new int(7) };
  TreeNode *t1 = buildBT(n, 7, 0);
  printTree(inOrderTraversal, t1);
  cout << maxDepth(t1) << endl;
  cout << maxDepth_(t1) << endl;
  return 0;
}