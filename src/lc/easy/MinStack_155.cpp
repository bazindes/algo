/*
  MinStack_155.cpp
  Created by: baz
  Date: 2019-07-12 14:56
*/

/**
 * Design a stack that supports push, pop, top, and retrieving the minimum
element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.


Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/*
My thought: use vector to keep the order from input, the last element is the top
of stack use min heap keep the min value
 */
class MinStack {
private:
  vector<int> v;
  priority_queue<int, vector<int>, greater<int>> q;

public:
  MinStack() {}
  // O(1)
  void push(int x) {
    v.push_back(x);
    q.push(x);
  }
  // O(n)
  void pop() {
    int x = *(v.end() - 1);
    vector<int> temp;
    while (q.top() != x) {
      temp.push_back(q.top());
      q.pop();
    }
    q.pop();
    for (int i : temp) {
      q.push(i);
    }
    v.pop_back();
  }
  // O(1)
  int top() { return *(v.end() - 1); }
  // O(1)
  int getMin() { return q.top(); }
};

class MinStack_ {
public:
  MinStack_() {}

  /*
   * @param number: An integer
   * @return: nothing
   * O(1)
   */
  void push(int number) {
    int min = number;
    if (!_data_stack.empty()) {
      if (_min_stack.top() < number) {
        min = _min_stack.top();
      }
    }

    _data_stack.push(number);
    _min_stack.push(min);
  }

  /*
   * @return: An integer
   * O(1)
   */
  int pop() {
    int top = _data_stack.top();
    _data_stack.pop();
    _min_stack.pop();
    return top;
  }

  // O(1)
  int top() { return _data_stack.top(); }

  /*
   * @return: An integer
   * O(1)
   */
  int getMin() { return _min_stack.top(); }

private:
  stack<int> _data_stack;
  stack<int> _min_stack;
};

int main() {
  MinStack *obj = new MinStack();
  obj->push(1);
  obj->push(5);
  obj->push(2);
  obj->push(8);
  obj->pop();
  int param_3 = obj->top();
  int param_4 = obj->getMin();
  cout << param_3 << " " << param_4 << endl;
  return 0;
}