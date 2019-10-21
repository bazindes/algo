/*
  SingleNumber_136.cpp
  Created by: baz
  Date: 2019-07-12 14:10
*/

/**
 * Given a non-empty array of integers, every element appears twice except for
one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it
without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
 */

#include <set>
#include <vector>
#include <iostream>

using namespace std;

// O(n) O(n)
int singleNumber(vector<int> &nums) {
  set<int> s;
  for (int i = 0; i < nums.size(); i++) {
    if (s.find(nums[i]) != s.end())
      s.erase(nums[i]);
    else
      s.insert(nums[i]);
  }
  return *s.begin();
}

// O(n) O(1)
int singleNumber_(vector<int> &nums) {
  int ans = 0;
  for (auto i : nums)
    ans ^= i;
  return ans;
}

// int main() {
//   vector<int> v1 = {2, 2, 1};
//   cout << singleNumber(v1) << endl;
//   vector<int> v2 = {4, 1, 2, 1, 2};
//   cout << singleNumber(v2) << endl;
//   return 0;
// }