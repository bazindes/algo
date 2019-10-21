/*
  PascalsTriangle_118.cpp
  Created by: baz
  Date: 2019-07-10 18:17
*/

/**
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above
it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 */

#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

vector<vector<int>> generate(int numRows) {
  vector<vector<int>> ans;
  if(numRows < 1) return ans;
  vector<int> v1 = {1};
  ans.push_back(v1);
  if(numRows == 1) return ans;
  vector<int> v2 = {1, 1};
  ans.push_back(v2);
  if(numRows == 2) return ans;
  int cur = 1;
  while(-- numRows > 1){
    vector<int> temp;
    temp.push_back(1);
    for(int i = 0; i < ans[cur].size() - 1; i ++){
      temp.push_back(ans[cur][i] + ans[cur][i+1]);
    }
    temp.push_back(1);
    cur ++;
    ans.push_back(temp);
  }
  return ans;
}

int main(){
  // cout << generate(5) << endl;
  return 0;
}