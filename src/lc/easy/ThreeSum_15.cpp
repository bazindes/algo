/*
  ThreeSum_15.cpp
  Created by: baz
  Date: 2019-05-14 16:38
*/

/*
Given an array nums of n integers, are there elements a, b, c in nums such that
a + b + c = 0? Find all unique triplets in the array which gives the sum of
zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <vector>
#include "Util.h"

using namespace std;

// O(n^2)
vector<vector<int> > threeSum(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  int i = 0;
  int n = nums.size();
  vector<vector<int> > ans;
  for (; i < n; i++) {
    if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
      int sum = 0 - nums[i];
      int lo = i + 1;
      int hi = n - 1;
      while (lo < hi) {
        if (nums[lo] + nums[hi] == sum) {
          vector<int> temp = {nums[i], nums[lo], nums[hi]};
          ans.push_back(temp);
          while (lo < hi && nums[lo] == nums[lo + 1])
            lo++;
          while (lo < hi && nums[hi] == nums[hi - 1])
            hi--;
          lo++;
          hi--;
        } else if (nums[lo] + nums[hi] < sum) {
          lo++;
        } else {
          hi--;
        }
      }
    }
  }
  return ans;
}
