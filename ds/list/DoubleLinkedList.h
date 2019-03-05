/*
    DoubleLinkedList.h
    Created by: baz
    Date: 2019-03-04 21:28
*/

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdlib.h>

struct DoubleLinkedListNode;

// define DoubleLinkedListNode
typedef struct
{
    void *val;
    struct DoubleLinkedListNode *prev;
    struct DoubleLinkedListNode *next;
} DoubleLinkedListNode;

// define DoubleLinkedList
typedef struct 
{
    DoubleLinkedListNode *head;
    DoubleLinkedListNode *tail;
    int count;
} DoubleLinkedList;

// create list & return
DoubleLinkedList *list_create();
// destroy list
void list_destroy(DoubleLinkedList *list);
// clear list
void list_clear(DoubleLinkedList *list);
// clear & destroy list
void list_clear_destroy(DoubleLinkedList *list);

// return size of list
#define list_count(A) ((A)->count)
// return head of list
#define list_head(A) ((A)->head ? (A)->head->val : NULL)
// return tail of list
#define list_tail(A) ((A)->tail ? (A)->tail->val : NULL)

// push an element to the tail of list
void list_push(DoubleLinkedList *list, void *val);
// pop out the tail of list & return
void *list_pop(DoubleLinkedList *list);

// add an element to the head of list
void list_unshift(DoubleLinkedList *list, void *val);
// remove the head of list & return
void *list_shift(DoubleLinkedList *list);

// remove specified node in list
void *list_remove(DoubleLinkedList *list, DoubleLinkedListNode *node);

#define list_foreach(L, S, M, V)        \
    DoubleLinkedListNode *_node = NULL; \
    DoubleLinkedListNode *V = NULL;     \
    for (V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif