/*
  ContainerWithMostWater_11.cpp
  Created by: baz
  Date: 2019-05-14 16:20
*/

/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at
coordinate (i, ai). n vertical lines are drawn such that the two endpoints of
line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

#include "../../util/pch.h"
using namespace std;

int maxArea(vector<int> &height) {
  int i = 0;
  int j = height.size() - 1;
  int ans = INT_MIN;
  int l, r;
  while (i < j) {
    l = height[i];
    r = height[j];
    if (l < r) {
      ans = max(ans, l * (j - i));
      i++;
    } else {
      ans = max(ans, r * (j - i));
      j--;
    }
  }
  return ans;
}

int main() {
  vector vc = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << maxArea(vc) << endl;
  return 0;
}