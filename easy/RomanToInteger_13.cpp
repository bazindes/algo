// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

// Example 1:

// Input: "III"
// Output: 3
// Example 2:

// Input: "IV"
// Output: 4
// Example 3:

// Input: "IX"
// Output: 9
// Example 4:

// Input: "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
// Example 5:

// Input: "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
// Accepted
// 360,889
// Submissions
// 701,189

#include <iostream>
#include <string>
#include <map>

using namespace std;

class RomanToInteger_13
{
  public:
    int romanToInt(string s);
    int romanToInt_(string s);
    void test();
};

int RomanToInteger_13::romanToInt(string s)
{
    map<char, int> m;
    m.insert({'I', 1});
    m.insert({'V', 5});
    m.insert({'X', 10});
    m.insert({'L', 50});
    m.insert({'C', 100});
    m.insert({'D', 500});
    m.insert({'M', 1000});
    int ans = 0;
    auto it = s.begin();
    for (; it < s.end(); it++)
    {
        if (*it == 'I')
        {
            if (*(it + 1) == 'V' || *(it + 1) == 'X')
            {
                ans -= m.find(*it)->second;
            }
            else
            {
                ans += m.find(*it)->second;
            }
        }
        else if (*it == 'X')
        {
            if (*(it + 1) == 'L' || *(it + 1) == 'C')
            {
                ans -= m.find(*it)->second;
            }
            else
            {
                ans += m.find(*it)->second;
            }
        }
        else if (*it == 'C')
        {
            if (*(it + 1) == 'D' || *(it + 1) == 'M')
            {
                ans -= m.find(*it)->second;
            }
            else
            {
                ans += m.find(*it)->second;
            }
        }
        else
        {
            ans += m.find(*it)->second;
        }
    }
    return ans;
}

int RomanToInteger_13::romanToInt_(string s)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int a = 0, b, ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        b = a;
        switch (s[i])
        {
        case 'I':
            a = 1;
            break;
        case 'V':
            a = 5;
            break;
        case 'X':
            a = 10;
            break;
        case 'L':
            a = 50;
            break;
        case 'C':
            a = 100;
            break;
        case 'D':
            a = 500;
            break;
        case 'M':
            a = 1000;
            break;
        default:
            a = 0;
        }
        if (i)
        {
            if (b < a && a <= b * 10)
                ans -= b;
            else
                ans += b;
        }
    }
    ans += a;
    return ans;
}

void RomanToInteger_13::test()
{
    string s1 = "III";
    string s2 = "IV";
    string s3 = "IX";
    string s4 = "LVIII";
    string s5 = "MCMXCIV";

    cout << romanToInt(s1) << endl;
    cout << romanToInt(s2) << endl;
    cout << romanToInt(s3) << endl;
    cout << romanToInt(s4) << endl;
    cout << romanToInt(s5) << endl;
}