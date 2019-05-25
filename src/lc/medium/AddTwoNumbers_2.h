//
// Created by baz on 2019-02-19.
//

#include "ds/list/LinkedList.h"

using namespace LinkedList;

class AddTwoNumbers_2 {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
  ListNode *addTwoNumbers_(ListNode *l1, ListNode *l2);
  void build();
};

void AddTwoNumbers_2::build() {
  ListNode l(0);
  ListNode l1(1);
  ListNode l2(2);
  ListNode l3(3);
  ListNode l4(4);
  l.next = &l1;
  l1.next = &l2;
  l2.next = &l3;
  l3.next = &l4;
  ListNode l5(5);
  ListNode l6(6);
  ListNode l7(7);
  ListNode l8(8);
  ListNode l9(9);
  l5.next = &l6;
  l6.next = &l7;
  l7.next = &l8;
  l8.next = &l9;

  // traverseListNode(&l);
  // traverseListNode(&l5);
  // traverseListNode(addTwoNumbers_(&l, &l5));
}

// O(n) O(1)
ListNode *AddTwoNumbers_2::addTwoNumbers_(ListNode *l1, ListNode *l2) {
  auto l3 = l1;
  for (;;) {
    if (l1 == nullptr) {
      return l3;
    }
    if (l2 != nullptr) {
      l1->val += l2->val;
      l2 = l2->next;
    }
    if (l1->val >= 10) {
      l1->val -= 10;
      if (l1->next == nullptr) {
        l1->next = new ListNode(1);
      } else {
        l1->next->val++;
      }
    }
    if (l1->next == nullptr && l2 != nullptr) {
      l1->next = l2;
      l2 = nullptr;
    }
    l1 = l1->next;
  }
}

// O(n) O(1)
ListNode *AddTwoNumbers_2::addTwoNumbers(ListNode *l1, ListNode *l2) {
  auto *ans = new ListNode;
  ListNode *a = ans;
  int carry = 0;
  while (l1 && l2) {
    int temp = l1->val + l2->val + carry;
    auto *l = new ListNode;
    if (temp > 9) {
      l->val = temp - 10;
      carry = 1;
    } else {
      l->val = temp;
      carry = 0;
    }
    ans->next = l;
    ans = ans->next;
    l1 = l1->next;
    l2 = l2->next;
  }

  while (l1) {
    int temp = l1->val + carry;
    auto *l = new ListNode;
    if (temp > 9) {
      l->val = temp - 10;
      carry = 1;
    } else {
      l->val = temp;
      carry = 0;
    }
    ans->next = l;
    ans = ans->next;
    l1 = l1->next;
  }

  while (l2) {
    int temp = l2->val + carry;
    auto *l = new ListNode;
    if (temp > 9) {
      l->val = temp - 10;
      carry = 1;
    } else {
      l->val = temp;
      carry = 0;
    }
    ans->next = l;
    ans = ans->next;
    l2 = l2->next;
  }

  if (carry) {
    auto *l = new ListNode(carry);
    ans->next = l;
  }

  return a->next;
}
