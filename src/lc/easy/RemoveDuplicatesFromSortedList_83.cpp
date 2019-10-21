/*
  RemoveDuplicatesFromSortedList_83.cpp
  Created by: baz
  Date: 2019-06-03 15:22
*/

/*
Given a sorted linked list, delete all duplicates such that each element appear
only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/

#include "LinkedList.h"

using namespace std;
using namespace LinkedList;

// O(n)
ListNode *deleteDuplicates(ListNode *head) {
  ListNode *prev = head;
  ListNode *runner = head->next;
  while (runner) {
    if (prev->val != runner->val) {
      prev->next = runner;
      prev = prev->next;
    }
    runner = runner->next;
    prev->next = nullptr;
  }
  return head;
}

// int main() {
//   int nums[] = {1, 1, 2};
//   ListNode *l1 = createLinkedList(nums, 3);
//   printLinkedList(l1);
//   l1 = deleteDuplicates(l1);
//   printLinkedList(l1);
//   int nums2[] = {1, 1, 2, 3, 3};
//   ListNode *l2 = createLinkedList(nums2, 5);
//   printLinkedList(l2);
//   l2 = deleteDuplicates(l2);
//   printLinkedList(l2);
// }