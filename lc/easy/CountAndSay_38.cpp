// The count-and-say sequence is the sequence of integers with the first five terms as following:

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.

// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

// Note: Each term of the sequence of integers will be represented as a string.

// Example 1:

// Input: 1
// Output: "1"
// Example 2:

// Input: 4
// Output: "1211"

#include <iostream>
#include <string>

using namespace std;

class CountAndSay_38
{
  private:
    string helper(string s)
    {
        string ans = "";
        int k = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != s[k])
            {
                ans += to_string(i - k);
                ans += s[k];
                k = i;
            }
            if (i == s.size() - 1)
            {
                ans += to_string(i - k + 1);
                ans += s[k];
            }
        }
        return ans;
    }

  public:
    string countAndSay(int n);
    string countAndSay_(int n);
    void test();
};

string CountAndSay_38::countAndSay(int n)
{
    if (n == 1)
    {
        return "1";
    }
    return helper(countAndSay(n - 1));
}

//O(n) O(1)
string CountAndSay_38::countAndSay_(int n)
{
    string res = "1", cur = "1";
    while (--n)
    {
        char ch = res[0];
        int count = 0;
        cur = "";
        for (int i = 0; i < res.size(); i++)
        {
            if (ch == res[i])
                count++;
            else
            {
                cur += count + '0';
                cur += ch;
                ch = res[i];
                count = 1;
            }
        }
        cur += count + '0';
        cur += ch;
        res = cur;
    }
    return res;
}

void CountAndSay_38::test()
{
    cout << countAndSay(1) << endl;
    cout << countAndSay(4) << endl;
}
