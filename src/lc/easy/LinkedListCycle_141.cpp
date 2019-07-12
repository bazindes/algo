/*
  LinkedListCycle_141.cpp
  Created by: baz
  Date: 2019-07-12 14:29
*/

/**
 * Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which
represents the position (0-indexed) in the linked list where tail connects to.
If pos is -1, then there is no cycle in the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the
second node.


Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the
first node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

Follow up:

Can you solve it using O(1) (i.e. constant) memory?
 */

#include "../../ds/list/LinkedList.cpp"
#include "../../util/pch.h"
using namespace std;
using namespace LinkedList;

// O(n) O(n)
bool hasCycle(ListNode *head) {
  set<ListNode *> s;
  while (head) {
    if (s.find(head) == s.end())
      s.insert(head);
    else
      return true;
    head = head->next;
  }
  return false;
}

// O(n) O(1)
bool hasCycle_(ListNode *head) {
  if (head == nullptr)
    return false;
  ListNode *fast = head->next;
  while (fast) {
    if (head == fast)
      return true;
    else {
      head = head->next;
      fast = fast->next;
      if (fast)
        fast = fast->next;
    }
  }
}

int main() {
  int nums[] = {3, 2, 0, -4};
  ListNode *l1 = createLinkedList(nums, 4);
  printLinkedList(l1);
  l1->next->next->next->next = l1->next;
  cout << hasCycle_(l1) << endl;
  return 0;
}