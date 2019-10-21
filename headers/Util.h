//
// Created by baz on 2019-02-19.
//

#include <iostream>
#include <vector>
#include "LinkedList.h"

#ifndef UTIL_H
#define UTIL_H

namespace util {

template <typename T> void preOrderTraversal(T &t) {}
template <typename T> void traverseMatrix(T t) {
  for (auto i : t) {
    for (auto j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

} // namespace util

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

#endif