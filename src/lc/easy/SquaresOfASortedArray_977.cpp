/*
  SquaresOfASortedArray_977.cpp
  Created by: baz
  Date: 2019-05-25 17:25
*/

/*
Given an array of integers A sorted in non-decreasing order, return an array of
the squares of each number, also in sorted non-decreasing order.

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

#include "../../util/pch.h"

using namespace std;

// O(lgn) O(1)
vector<int> sortedSquares(vector<int> &A) {
  for (int &a : A) {
    a = a * a;
  }
  sort(A.begin(), A.end());
  return A;
}

// O(n) O(n)
vector<int> sortedSquares_(vector<int> &A){
  vector<int> ans(A.size(), 0);
  int i = 0;
  int j = A.size() - 1;
  int k = j;
  
  while( i <= j ){
    int curI = abs(A[i]);
    int curJ = abs(A[j]);
    if(curI <= curJ) {
      ans[k --] = pow(A[j --], 2);
    }else{
      ans[k --] = pow(A[i ++], 2);
    }
  }
  return ans;
}

int main(){
  vector<int> a1 = {-4,-1,0,3,10};
  vector<int> a2 = {-7,-3,2,3,11};

  cout << sortedSquares_(a1) << endl;
  cout << sortedSquares_(a2) << endl;

  return 0;
}