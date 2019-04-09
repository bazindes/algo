/*
  Contains Duplicate_217.cpp
  Created by: baz
  Date: 2019-03-30 02:01

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the
array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    // if(nums.size() == 0) return false;
    // set<int> set;
    // for(int i : nums){
    //     if(set.find(i) != set.end())
    //         return true;
    //     set.insert(i);
    // }
    // return false;
    if (nums.size() == 0)
      return false;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == nums[i + 1])
        return true;
    }

    return false;
  }
};

static const auto speedup = []() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  return 0;
}();