/*
  LengthOfLastWord_58.cpp
  Created by: baz
  Date: 2019-05-29 19:54
*/

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/

#include <string>
#include <iostream>

using namespace std;

// O(n) O(1)
int lengthOfLastWord(string s) {
  if(s.empty()) return 0;
  size_t pos = s.find_last_of(' ');
  if(pos == string::npos) return s.size();
  if(pos + 1 == s.size()) {
    return lengthOfLastWord(s.substr(0, s.size() - 1));
  }
  string word = s.substr(++pos);
  return word.size();
}

int main(){
  cout << lengthOfLastWord("Hello World") << endl;
  cout << lengthOfLastWord("a ") << endl;
}