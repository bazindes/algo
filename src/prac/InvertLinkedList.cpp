/*
  InvertLinkedList.cpp
  Created by: baz
  Date: 2019-03-29 17:10
*/
#include "LinkedList.h"
// static LinkedListNode *helper(LinkedListNode *node) {
//   if (!node->next)
//     return node;
//   LinkedListNode *cur = node;
//   LinkedListNode *prev = helper(node->next);
//   prev->next = cur;
//   return cur;
// }

LinkedList::ListNode *invert(LinkedList::ListNode *head) {
  LinkedList::ListNode *cur = head;
  LinkedList::ListNode *nxt = nullptr;
  LinkedList::ListNode *prev = nullptr;

  while (cur) {
    nxt = cur->next;
    cur->next = prev;
    prev = cur;
    cur = nxt;
  }

  return prev;
}
