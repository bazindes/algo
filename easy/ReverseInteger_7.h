//
// Created by baz on 2019-02-20.
//

#ifndef ALGO_REVERSEINTEGER_7_H
#define ALGO_REVERSEINTEGER_7_H

//Given a 32-bit signed integer, reverse digits of an integer.
//
//Example 1:
//
//Input: 123
//Output: 321
//Example 2:
//
//Input: -123
//Output: -321
//Example 3:
//
//Input: 120
//Output: 21
//Note:
//Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
// For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x);
    int reverse_(int x);

    void build();
};

//O(logn) O(1)
int Solution::reverse(int x) {
    if (x < 10 && x > -10)
        return x;
    int sign = x > 0 ? 1 : -1;
    long temp = x;
    if (sign == -1) temp = -temp;
    long ans = 0;
    while (temp) {
        ans += (temp % 10);
        temp /= 10;
        ans *= 10;
    }
    ans = ans * sign / 10;
    if (ans > INT_MAX || ans < INT_MIN) return 0;
    return ans;
}

//O(logn) O(1)
int Solution::reverse_(int x) {

    long long int ans = 0;
    while (x) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    if (ans < INT_MIN || ans > INT_MAX)
        return 0;
    return ans;
}

void Solution::build() {
    int a = 1534236469;
    int b = -235;
    cout << reverse(a) << endl;
    cout << reverse(b) << endl;
}

#endif //ALGO_REVERSEINTEGER_7_H
