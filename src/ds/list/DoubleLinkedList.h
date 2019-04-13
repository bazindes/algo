/*
    DoubleLinkedList.h
    Created by: baz
    Date: 2019-03-04 21:28
*/

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

namespace DoubleLinkedList {

// define DoubleLinkedListNode
struct ListNode {
public:
  int val;
  struct ListNode *prev;
  struct ListNode *next;

  ListNode();
  ListNode(int);
  ~ListNode();
};

void printList(ListNode *);

} // namespace DoubleLinkedList

#endif