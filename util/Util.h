//
// Created by baz on 2019-02-19.
//

#ifndef ALGO_UTIL_H
#define ALGO_UTIL_H

#include <iostream>

using namespace std;
namespace util
{

class ListNode
{
  public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

void traverse(ListNode *l)
{
    while (l)
    {
        cout << l->val ;
        l = l->next;
        if(l){
            cout << " -> ";
        }
    }
    cout << endl;
}

} // namespace util

#endif //ALGO_UTIL_H
