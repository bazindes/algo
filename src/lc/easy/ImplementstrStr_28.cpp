// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if
// needle is not part of haystack.

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Clarification:

// What should we return when needle is an empty string? This is a great
// question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty
// string. This is consistent to C's strstr() and Java's indexOf().

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ImplementstrStr_28 {
public:
  int strStr(string haystack, string needle);
  int strStr_(string haystack, string needle);
  void test();
  int strStrKMP(string haystack, string needle);

private:
  vector<int> kmpProcess(string needle) {
    int n = needle.size();
    vector<int> lps(n, 0);
    int i = 1;
    int len = 0;
    for (; i < n;) {
      if (needle[i] == needle[len]) {
        lps[i++] = ++len;
      } else if (len) {
        len = lps[len - 1];
      } else {
        lps[i++] = 0;
      }
    }
    return lps;
  }
};

int ImplementstrStr_28::strStr(string haystack, string needle) {
  int ans = 0;
  if (needle.empty()) {
    return ans;
  }
  if (haystack.size() < needle.size()) {
    cout << haystack.size() << " ---- " << needle.size() << endl;
    return -1;
  }
out:
  for (int i = 0; i < haystack.size(); i++) {
    int j = 0;
    if (haystack[i] != needle[j]) {
      continue;
    }
    if (haystack.size() - i + 1 < needle.size()) {
      return -1;
    }
    int temp = i;
    for (; j < needle.size(); j++) {
      if (haystack[temp] != needle[j]) {
        goto out;
      }
      temp++;
    }
    return i;
  }

  return -1;
}

int ImplementstrStr_28::strStr_(string haystack, string needle) {
  int m = haystack.size(), n = needle.size();
  for (int i = 0; i <= m - n; i++) {
    int j = 0;
    for (; j < n; j++) {
      if (haystack[i + j] != needle[j]) {
        break;
      }
    }
    if (j == n) {
      return i;
    }
  }
  return -1;
}

int ImplementstrStr_28::strStrKMP(string haystack, string needle) {
  int m = haystack.size(), n = needle.size();
  if (!n) {
    return 0;
  }
  vector<int> lps = kmpProcess(needle);
  int i = 0, j = 0;
  for (; i < m;) {
    if (haystack[i] == needle[j]) {
      i++;
      j++;
    }
    if (j == n) {
      return i - j;
    }
    if (i < m && haystack[i] != needle[j]) {
      j ? j = lps[j - 1] : i++;
    }
  }

  return -1;
}

void ImplementstrStr_28::test() {
  cout << strStr("hello", "el") << endl;
  cout << strStr_("hello", "el") << endl;
  cout << strStrKMP("hello", "el") << endl;
  cout << strStr("mississippi", "mississippi") << endl;
  cout << strStr_("mississippi", "mississippi") << endl;
  cout << strStrKMP("mississippi", "mississippi") << endl;
  cout << strStr("aaaaa", "bba") << endl;
  cout << strStr_("aaaaa", "bba") << endl;
  cout << strStrKMP("aaaaa", "bba") << endl;
}
