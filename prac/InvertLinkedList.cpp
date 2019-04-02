/*
  InvertLinkedList.cpp
  Created by: baz
  Date: 2019-03-29 17:10
*/
#include "../ds/list/LinkedList.h"

// static LinkedListNode *helper(LinkedListNode *node) {
//   if (!node->next)
//     return node;
//   LinkedListNode *cur = node;
//   LinkedListNode *prev = helper(node->next);
//   prev->next = cur;
//   return cur;
// }

LinkedList *invert(LinkedList *list) {
  LinkedListNode *cur = list->head;
  LinkedListNode *n;
  LinkedListNode *prev;

  while (cur) {
    n = cur->next;
    cur->next = prev;
    prev = cur;
    cur = n;
  }

  list->head = prev;
  return list;
}
