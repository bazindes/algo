/*
    DoubleLinkedList.c
    Created by: baz
    Date: 2019-03-04 22:01
*/

#include "DoubleLinkedList.h"

DoubleLinkedListNode::DoubleLinkedListNode()
    : val(0), prev(nullptr), next(nullptr) {}
DoubleLinkedListNode::DoubleLinkedListNode(int x)
    : val(x), prev(nullptr), next(nullptr) {}
DoubleLinkedListNode::~DoubleLinkedListNode() {}

DoubleLinkedList::DoubleLinkedList() : size(0), head(nullptr), tail(nullptr) {}
DoubleLinkedList::~DoubleLinkedList() {}