/*
  ValidPalindrome_125.cpp
  Created by: baz
  Date: 2019-07-12 13:40
*/

/**
 * Given a string, determine if it is a palindrome, considering only
alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid
palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

 */

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
  int i = 0;
  int j = s.size() - 1;
  while (i < j) {
    while (!isalnum(s[i]) && i < j)
      i++;
    while (!isalnum(s[j]) && i < j)
      j--;
    if (toupper(s[i]) != toupper(s[j]))
      return false;
    i++;
    j--;
  }
  return true;
}

int main() { 
  cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
  cout << isPalindrome("race a car") << endl;
  cout << isPalindrome("") << endl;
  cout << isPalindrome("OP") << endl;
  return 0; 
}