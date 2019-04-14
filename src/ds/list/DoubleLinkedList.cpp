/*
    DoubleLinkedList.c
    Created by: baz
    Date: 2019-03-04 22:01
*/

#include "../../util/pch.h"

DoubleLinkedList::ListNode::ListNode() : val(0), prev(nullptr), next(nullptr) {}
DoubleLinkedList::ListNode::ListNode(int x)
    : val(x), prev(nullptr), next(nullptr) {}
DoubleLinkedList::ListNode::~ListNode() {}

void DoubleLinkedList::printList(DoubleLinkedList::ListNode *head) {
    ListNode *cur = head;
    std::cout << " | ";
    while (cur)
    {
        std::cout << cur -> val << " | ";
        cur = cur -> next;
    }
    std::cout << std::endl;
}
