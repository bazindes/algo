/*
  PlusOne_66.cpp
  Created by: baz
  Date: 2019-05-29 20:22
*/

/*
Given a non-empty array of digits representing a non-negative integer, plus one
to the integer.

The digits are stored such that the most significant digit is at the head of the
list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number
0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

vector<int> plusOne(vector<int> &digits) {
  int s = digits.size() - 1;
  int carry = 0;
  int i = s;
  for(; i >= 0; i --){
    int temp = digits[i] + carry;
    if(i == s){
      temp ++;
    }
    if(temp > 9){
      digits[i] = 0;
      carry = 1;
    }else{
      digits[i] = temp;
      carry = 0;
    }
  }
  if(carry == 1) digits.insert(digits.begin(), 1);
  return digits;
}

int main(){
  vector<int> v1 = {1,2,3};
  // cout << plusOne(v1) << endl;
  vector<int> v2 = {9,9,9,9};
  // cout << plusOne(v2) << endl;
}