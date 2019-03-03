// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

#include "../util/util.h"
#include <iostream>

using namespace std;

class MergeTwoSortedLists_21
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
    ListNode *mergeTwoLists_(ListNode *l1, ListNode *l2);
    void test();
};

//O(n) O(1)
ListNode *MergeTwoSortedLists_21::mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1 || !l2)
    {
        return l1 ? l1 : l2;
    }

    ListNode *ans = new ListNode(0);
    ListNode *temp = ans;
    while (1)
    {
        if (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                ans->next = l1;
                l1 = l1->next;
            }
            else
            {
                ans->next = l2;
                l2 = l2->next;
            }
            ans = ans->next;
        }
        else if (l1 || l2)
        {
            if (l1)
            {
                ans->next = l1;
                l1 = l1->next;
            }
            else
            {
                ans->next = l2;
                l2 = l2->next;
            }
            ans = ans->next;
        }
        else
        {
            break;
        }
    }
    return temp->next;
}

ListNode *MergeTwoSortedLists_21::mergeTwoLists_(ListNode *l1, ListNode *l2)
{
    return nullptr;
}

void MergeTwoSortedLists_21::test()
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(4);
    n1.next = &n2;
    n2.next = &n3;
    ListNode n4(1);
    ListNode n5(3);
    ListNode n6(4);
    n4.next = &n5;
    n5.next = &n6;
    // traverse(&n1);
    // traverse(&n4);
    traverseListNode(mergeTwoLists(&n1, &n4));
}

