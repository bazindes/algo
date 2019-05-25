//
// Created by baz on 2019-02-20.
//

// Determine whether an integer is a palindrome. An integer is a palindrome when
// it reads the same backward as forward.
//
// Example 1:
//
// Input: 121
// Output: true
// Example 2:
//
// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it
// becomes 121-. Therefore it is not a palindrome. Example 3:
//
// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Follow up:
//
// Coud you solve it without converting the integer to a string?

#ifndef ALGO_PALINDROMENUMBER_9_H
#define ALGO_PALINDROMENUMBER_9_H

#include <iostream>
#include <string>

using namespace std;

class PalindromeNumber_9 {
public:
  bool isPalindrome(int x);
  void test();
};

bool PalindromeNumber_9::isPalindrome(int x) {

  string s = to_string(x);

  auto start = s.begin();
  auto end = s.end() - 1;
  while (*start == *end) {
    start++;
    end--;
    //       cout << "start: " << *start << " end: " << *end << endl;
  }
  return end < start;
}

void PalindromeNumber_9::test() {
  int x = 12321;
  int y = 123321;
  int z = 123435;
  string s = "abccba";
  cout << isPalindrome(x) << endl
       << isPalindrome(y) << endl
       << isPalindrome(z) << endl;
}

#endif // ALGO_PALINDROMENUMBER_9_H
