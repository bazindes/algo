/*
    ListNode.h
    Created by: baz
    Date: 2019-03-03 15:59
*/
#ifndef LISTNODE_H
#define LISTNODE_H

namespace LinkedList {

struct ListNode {
  int val;
  ListNode *next;

  ListNode();
  ListNode(int);
  ~ListNode();
};

void printLinkedList(ListNode *);
ListNode *createLinkedList(int nums[], int n);

} // namespace LinkedList

#endif