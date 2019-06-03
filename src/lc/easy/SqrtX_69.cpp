/*
  SqrtX_69.cpp
  Created by: baz
  Date: 2019-06-03 14:44
*/

/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a
non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only
the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
             the decimal part is truncated, 2 is returned.
*/

#include <iostream>
#include <cmath>

using namespace std;

int mySqrt(int x) {
  return sqrt(x);
}

// O(logn)
int mySqrt_(int x) {
  if(x == 0 || x == 1) return x;
  long long l = 1;
  long long r = x;
  long long mid;
  int ans = 0;
  while (l <= r) {
    mid = (l + r)/2;
    if(mid * mid == x){
      return mid;
    }else if(mid * mid < x){
      ans = mid;
      l = mid + 1;
    }else {
      r = mid - 1;
    }
  }
  return ans;
}

int main(){
  cout << mySqrt_(8) << endl;
  cout << mySqrt_(4) << endl;
  cout << mySqrt_(2) << endl;
}