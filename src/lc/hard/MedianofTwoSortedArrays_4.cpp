/*
  MedianofTwoSortedArrays_4.cpp
  Created by: baz
  Date: 2019-08-01 15:39
*/

/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should
be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
 */

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  int xs = nums1.size();
  int ys = nums2.size();
  int i = 0;
  int j = xs + ys - 1;
  int x = 0;
  int y = ys - 1;
  while(nums1[x] != nums2[y]){
    
  }

}

// int main(){

//   return 0;
// }