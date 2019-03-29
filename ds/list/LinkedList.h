/*
    ListNode.h
    Created by: baz
    Date: 2019-03-03 15:59
*/
#ifndef LISTNODE_H
#define LISTNODE_H

class LinkedListNode {
public:
  int val;
  LinkedListNode *next;

  LinkedListNode();
  LinkedListNode(int x);
  ~LinkedListNode();
};

class LinkedList {
public:
  int size;
  LinkedListNode *head;
  LinkedListNode *tail;

  LinkedList();
  ~LinkedList();
};

#endif