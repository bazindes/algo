// Given a string containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.

// Example 1:

// Input: "()"
// Output: true
// Example 2:

// Input: "()[]{}"
// Output: true
// Example 3:

// Input: "(]"
// Output: false
// Example 4:

// Input: "([)]"
// Output: false
// Example 5:

// Input: "{[]}"
// Output: true

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class ValidParentheses_20 {
public:
  bool isValid(string s);
  bool isValid_(string s);
  void test();

private:
  char exch(char c);
};

bool ValidParentheses_20::isValid(string s) {
  stack<char> st;
  auto i = s.begin();
  for (; i < s.end(); i++) {
    if (*i == '(' || *i == '{' || *i == '[') {
      st.push(exch(*i));
      continue;
    }
    if (st.empty()) {
      return 0;
    }
    auto temp = st.top();
    st.pop();
    if (temp != *i) {
      return 0;
    }
  }
  return !st.size();
}

char ValidParentheses_20::exch(char c) {
  switch (c) {
  case '(':
    return ')';
  case '[':
    return ']';
  case '{':
    return '}';
  default:
    return 0;
  }
}

bool ValidParentheses_20::isValid_(string s) { return 0; }

void ValidParentheses_20::test() {
  string s1 = "()";
  string s2 = "()[]{}";
  string s3 = "(]";
  string s4 = "([)]";
  string s5 = "{[]}";

  cout << isValid(s1) << endl;
  cout << isValid(s2) << endl;
  cout << isValid(s3) << endl;
  cout << isValid(s4) << endl;
  cout << isValid(s5) << endl;
}