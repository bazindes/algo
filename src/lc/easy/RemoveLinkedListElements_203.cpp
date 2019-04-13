
/*
  RemoveLinkedListElements_203.cpp
  Created by: baz
  Date: 2019-04-02 19:48
*/

#include "../../ds/list/LinkedList.h"

LinkedListNode *removeElements(LinkedListNode *head, int val) {
  LinkedListNode *fake = new LinkedListNode(0);
  // corner case, ({1,1,1} 1)
  while (head) {
    if (head->val != val)
      break;
    head = head->next;
  }
  // normal code
  fake->next = head;
  LinkedListNode *runner = head;
  LinkedListNode *prev = fake;
  while (runner) {
    if (runner->val != val) {
      prev->next = runner;
      prev = runner;
    } 
    runner = runner->next;
  }
  // corner case, end with val
  prev -> next = runner;
  return fake->next;
}