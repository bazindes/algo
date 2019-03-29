/*
    DoubleLinkedList.h
    Created by: baz
    Date: 2019-03-04 21:28
*/

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdlib.h>

struct DoubleLinkedListNode;

// define DoubleLinkedListNode
class DoubleLinkedListNode {
public:
  int val;
  struct DoubleLinkedListNode *prev;
  struct DoubleLinkedListNode *next;

  DoubleLinkedListNode();
  DoubleLinkedListNode(int);
  ~DoubleLinkedListNode();
};

// define DoubleLinkedList
class DoubleLinkedList {
public:
  int size;
  DoubleLinkedListNode *head;
  DoubleLinkedListNode *tail;

  DoubleLinkedList();
  ~DoubleLinkedList();
};

#endif