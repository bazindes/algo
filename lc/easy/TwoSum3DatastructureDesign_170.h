/*
  TwoSum3DatastructureDesign_170.cpp
  Created by: baz
  Date: 2019-04-02 02:53
*/
/**
 * Design and implement a TwoSum class. It should support the following
operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example 1:

add(1); add(3); add(5);
find(4) -> true
find(7) -> false
Example 2:

add(3); add(1); add(2);
find(3) -> true
find(6) -> false
*/

#include <map>
#include <unordered_set>
using namespace std;
// TLE
// class TwoSum {
// public:
//   set<int> nums;
//   set<int> sums;
//   /** Initialize your data structure here. */
//   TwoSum() {}

//   /** Add the number to an internal data structure.. */
//   void add(int number) {
//     for (int n : nums) {
//       sums.insert(n + number);
//     }
//     nums.insert(number);
//   }

//   /** Find if there exists any pair of numbers which sum is equal to the
//   value.
//    */
//   bool find(int value) { return sums.find(value) != sums.end(); }
// };

class TwoSum {
public:
  map<int, int> nums;
  TwoSum() {}
  ~TwoSum() {}
  void add(int number);
  bool find(int value);
};

class TwoSum_ {
    unordered_multiset<int> nums;
public:
    TwoSum_(){}
    ~TwoSum_(){}
    void add(int number) {
        nums.insert(number);
    }
    bool find(int value) {
        for (int i : nums) {
            int count = i == value - i ? 1 : 0;
            if (nums.count(value - i) > count) {
                return true;
            }
        }
        return false;
    }
};