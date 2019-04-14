/*
    ListNode.cpp
    Created by: baz
    Date: 2019-03-03 15:50
*/
#include "../../util/pch.h"

LinkedList::ListNode::ListNode():val(0), next(nullptr) {}
LinkedList::ListNode::ListNode(int x):val(x), next(nullptr) {}
LinkedList::ListNode::~ListNode() {}

void LinkedList::printLinkedList(LinkedList::ListNode *head) {
  LinkedList::ListNode *cur = head;

  while (cur) {
    std::cout << " | ";
    std::cout << cur->val;
    cur = cur->next;
  }
  std::cout << " |" << std::endl;
}

LinkedList::ListNode *LinkedList::createLinkedList(int nums[], int n) {
  if(nums){
    ListNode *cur = new ListNode;
    ListNode *dummy = cur;
    for(int i = 0; i < n; ++ i){
      ListNode *temp = new ListNode(nums[i]);
      dummy -> next = temp;
      dummy = dummy -> next;
    }
    return cur -> next;
  }
  return nullptr;
}