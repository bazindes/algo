/*
  MergeSortedArray_88.cpp
  Created by: baz
  Date: 2019-06-03 16:10
*/

/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one
sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m +
n) to hold additional elements from nums2. Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

#include <vector>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
  int i = m - 1;
  int j = n - 1;
  int k = m + n - 1;
  while(i > -1 && j > -1){
    if(nums1[i] > nums2[j]){
      nums1[k --] = nums1[i --];
    }else{
      nums1[k --] = nums2[j --];
    }
  }
  while(j > -1){
    nums1[k--] = nums2[j --];
  }
}

int main(){
  vector<int> v1 = {1,2,3,0,0,0};
  vector<int> v2 = {2,5,6};
  merge(v1, 3, v2, 3);
  // cout << v1 << endl;
}