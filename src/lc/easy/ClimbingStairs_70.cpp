/*
  ClimbingStairs_70.cpp
  Created by: baz
  Date: 2019-06-03 14:58
*/

/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you
climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

#include <iostream>

using namespace std;

// O(2^n)
int climbStairs(int n) {
  if(n == 0) return 1;
  if(n < 0) return 0;
  return climbStairs(n - 1) + climbStairs(n - 2);
}

int climbStairs_(int n) {
  if(n < 2) return n;
  int map[n + 1];
  map[0] = 0;
  map[1] = 1;
  map[2] = 2;
  int i = 3;
  for( ; i <= n; i ++){
    map[i] = map[i - 1] + map[i - 2];
  }
  return map[n];
}


int main() {
  cout << climbStairs_(2) << endl;
  cout << climbStairs_(3) << endl;
}