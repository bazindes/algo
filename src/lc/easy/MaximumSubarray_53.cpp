/*
  MaximumSubarray_53.cpp
  Created by: baz
  Date: 2019-04-15 21:56
*/

/**
 *
Given an integer array nums, find the contiguous subarray (containing at least
one number) which has the largest sum and return its sum. Example: Input:
[-2,1,-3,4,-1,2,1,-5,4], Output: 6 Explanation: [4,-1,2,1] has the largest sum
= 6. Follow up:

If you have figured out the O(n) solution, try coding another solution using the
divide and conquer approach, which is more subtle.
*/

#include "../../util/pch.h"

using namespace std;

int maxSubArray(vector<int> &nums) {
  int p = 0;
  int maxs = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
    p += nums[i];
    if (p < nums[i]) {
      p = nums[i];
    }
    maxs = maxs < p ? p : maxs;
  }
  return maxs;
}

int main(void) {
  vector<int> vc = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << maxSubArray(vc) << endl;
  return 0;
}