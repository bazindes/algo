/*
    ListNode.cpp
    Created by: baz
    Date: 2019-03-03 15:50
*/
#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedListNode::LinkedListNode() : val(0), next(nullptr) {}
LinkedListNode::LinkedListNode(int x) : val(x), next(nullptr) {}
LinkedListNode::~LinkedListNode() {}

LinkedList::LinkedList() : size(0), head(nullptr) {}
LinkedList::~LinkedList() {}

LinkedList::LinkedList(int x, int *nums) {
    size = x;
    head = new LinkedListNode(*nums);
    nums ++;

    LinkedListNode *cur = head;
    LinkedListNode *node;

    while(-- x){
        node = new LinkedListNode(*nums);
        cur->next = node;
        cur = cur -> next;
        nums ++;
    }

}

void LinkedList::printLinkedList() {
  LinkedListNode *cur = head;
  
  while (cur) {
    cout << " | ";
    cout << cur->val;
    cur = cur->next;
  }
  cout << " |" << endl;
  
}