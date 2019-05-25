
/*
  RemoveLinkedListElements_203.cpp
  Created by: baz
  Date: 2019-04-02 19:48
*/

#include "../util/pch.h"

using namespace LinkedList;

ListNode *removeElements(ListNode *head, int val) {
  ListNode *fake = new ListNode(0);
  // corner case, ({1,1,1} 1)
  while (head) {
    if (head->val != val)
      break;
    head = head->next;
  }
  // normal code
  fake->next = head;
  ListNode *runner = head;
  ListNode *prev = fake;
  while (runner) {
    if (runner->val != val) {
      prev->next = runner;
      prev = runner;
    }
    runner = runner->next;
  }
  // corner case, end with val
  prev->next = runner;
  return fake->next;
}