/*
    ListNode.h
    Created by: baz
    Date: 2019-03-03 15:59
*/
#ifndef LISTNODE_H
#define LISTNODE_H

class ListNode
{
  public:
    int val;
    ListNode *next;

    ListNode();
    ListNode(int x);
    ~ListNode();
};

#endif