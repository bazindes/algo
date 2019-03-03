//
// Created by baz on 2019-02-19.
//
#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include "mtype/ListNode.h"

using namespace std;

inline void traverseListNode(ListNode *l)
{
    while (l)
    {
        cout << l->val;
        l = l->next;
        if (l)
        {
            cout << " -> ";
        }
    }
    cout << endl;
}

#endif