/*
  pch.h  (precompiled headers)
  Created by: baz
  Date: 2019-04-13 14:05
*/

#ifndef PCH_H
#define PCH_H

// common usage
#include <iostream>
#include <algorithm>
#include <functional>
#include <memory>
#include <thread>
#include <utility>
#include <cmath>

// data structures
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

// my ds
#include "../ds/list/LinkedList.h"
#include "../ds/list/DoubleLinkedList.h"
#include "../ds/tree/BinaryTree.h"

#endif

namespace pch {

template <typename T> void traverseMatrix(T t) {
  for (auto i : t) {
    for (auto j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

} // namespace pch

template<typename T> std::ostream& operator<<(std::ostream &os, const std::vector<T> &A){
  os << "| ";
  for(auto &a : A){
    os << a << " | ";
  }
  return os;
}

template<typename T> std::ostream& operator<<(std::ostream &os, LinkedList::ListNode *head){
  LinkedList::ListNode *cur = head;
  while (cur) {
    os << " | ";
    os << cur->val;
    cur = cur->next;
  }
  os << " |" << std::endl;
  return os;
}