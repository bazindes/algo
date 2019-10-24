/*
  BestTimeToBuyAndSellStock_121.cpp
  Created by: baz
  Date: 2019-07-10 18:52
*/

/**
 * Say you have an array for which the ith element is the price of a given stock
on day i.

If you were only permitted to complete at most one transaction (i.e., buy one
and sell one share of the stock), design an algorithm to find the maximum
profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit =
6-1 = 5. Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

 */

#include <vector>
#include "gtest/gtest.h"

// O(n)
int maxProfit(std::vector<int> &prices) {
  int profit = 0;
  if(prices.empty()) return profit;
  int prev = prices[0];
  for(int i=1; i<prices.size(); i++){
    profit = std::max(profit, prices[i] - prev);
    prev = std::min(prices[i], prev);
  }
  return profit;
}

TEST(maxProfit , maxProfit) {
  std::vector<int> v1 = {7, 1, 5, 3, 6, 4};
  EXPECT_EQ(maxProfit(v1), 5);
  std::vector<int> v2 = {1, 2, 3, 4, 5};
  EXPECT_EQ(maxProfit(v2), 4);
  std::vector<int> v3 = {7, 6, 4, 3, 1};
  EXPECT_EQ(maxProfit(v3), 0);
}