/*
    ListNode.cpp
    Created by: baz
    Date: 2019-03-03 15:50
*/
#include "LinkedList.h"

LinkedListNode::LinkedListNode() : val(0), next(nullptr) {}
LinkedListNode::LinkedListNode(int x) : val(x), next(nullptr) {}
LinkedListNode::~LinkedListNode() {}

LinkedList::LinkedList() : size(0), head(nullptr), tail(nullptr) {}
LinkedList::~LinkedList() {}