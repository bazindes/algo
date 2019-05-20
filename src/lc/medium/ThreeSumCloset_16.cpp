/*
  ThreeSumCloset_16.cpp
  Created by: baz
  Date: 2019-05-14 19:46
*/

/*
Given an array nums of n integers and an integer target, find three integers in
nums such that the sum is closest to target. Return the sum of the three
integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include "../../util/pch.h"
using namespace std;

// O(n)
int threeSumClosest(vector<int> &nums, int target) {
  sort(nums.begin(), nums.end());
  int i = 0;
  int n = nums.size();
  int ans = nums[0] + nums[1] + nums[2];
  for (; i < n - 2; i++) {
    if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
      int lo = i + 1;
      int hi = n - 1;
      while (lo < hi) {
        int cur = nums[i] + nums[lo] + nums[hi];
        if (cur == target) {
          return cur;
        }
        if (abs(target - cur) < abs(target - ans)) {
          ans = cur;
        }
        if (cur > target) {
          hi--;
        } else {
          lo++;
        }
      }
    }
  }
  return ans;
}

int main() {
  vector<int> nums = {-1, 2, 1, -4};
  int tar = 1;
  cout << threeSumClosest(nums, tar) << endl;
  return 0;
}
