/*
  AddBinary_67.cpp
  Created by: baz
  Date: 2019-05-29 20:38
*/

/* Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101" */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/*
ascii: '0' = 48 , '1' = 49
*/
string addBinary(string a, string b) {
  if (a.size() < b.size())
    return addBinary(b, a);
  if (b.empty())
    return a;
  int i = a.size() - 1;
  int j = b.size() - 1;
  int carry = 0;
  while (i > -1 && j > -1) {
    if (j > -1) {
      int temp = a[i] - '0' + b[j] - '0' + carry;
      if (temp > 1) {
        a[i] = '0';
        if (temp > 2) {
          a[i] = '1';
        }
        carry = 1;
      } else if (temp == 1) {
        a[i] = '1';
        carry = 0;
      }
      j--;
    }
    i--;
  }
  while (i > -1) {
    int temp = a[i] - '0' + carry;
    if (temp > 1) {
      a[i] = '0';
      carry = 1;
    } else if (temp == 1) {
      a[i] = '1';
      carry = 0;
    }
    i--;
  }
  if(carry == 1) a = '1' + a;
  return a;
}

int main() {
  string a = "11", b = "1";
  cout << addBinary(a, b) << endl;
  a = "1010", b = "1011";
  cout << addBinary(a, b) << endl;
}