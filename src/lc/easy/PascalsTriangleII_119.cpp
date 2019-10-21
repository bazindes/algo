/*
  PascalsTriangle_118.cpp
  Created by: baz
  Date: 2019-07-10 18:17
*/

/**
 Given a non-negative index k where k ≤ 33, return the kth index row of the
Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above
it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
 */

#include <iostream>
#include <vector>
#include "Util.h"

using namespace std;

vector<int> getRow(int rowIndex) {
  vector<int> ans(rowIndex + 1);
  ans[0] = 1;
  for(int i= 0; i <= rowIndex; i++){
    for(int j = i; j > 0; j --){
      ans[j] = ans[j] + ans[j - 1];
    }
  }
  return ans;
}

// int main() {
//   // cout << getRow(5) << endl;
//   return 0;
// }