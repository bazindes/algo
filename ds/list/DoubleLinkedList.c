/*
    DoubleLinkedList.c
    Created by: baz
    Date: 2019-03-04 22:01
*/

#include "DoubleLinkedList.h"
#include "../../test/dbg.h"

DoubleLinkedList *list_create()
{
    return calloc(1, sizeof(DoubleLinkedList));
}

void list_destroy(DoubleLinkedList *list)
{
    list_foreach(list, head, next, cur)
    {
        if (cur->prev)
        {
            free(cur->prev);
        }
    }

    free(list->tail);
    free(list);
}

void list_clear(DoubleLinkedList *list)
{
    list_foreach(list, head, next, cur)
    {
        free(cur->val);
    }
}

void list_clear_destroy(DoubleLinkedList *list)
{
    list_clear(list);
    list_destroy(list);
}

void list_push(DoubleLinkedList *list, void *val)
{
    DoubleLinkedListNode *node = calloc(1, sizeof(DoubleLinkedListNode));
    check_mem(node);
    node->val = val;
    if (list->tail == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }

    list->count++;

error:
    return;
}

void *list_pop(DoubleLinkedList *list)
{
    DoubleLinkedListNode *node = list->tail;
    return node != NULL ? list_remove(list, node) : NULL;
}

void list_unshift(DoubleLinkedList *list, void *val)
{
    DoubleLinkedListNode *node = calloc(1, sizeof(DoubleLinkedListNode));
    check_mem(node);

    node->val = val;

    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }

    list->count++;

error:
    return;
}

void *list_shift(DoubleLinkedList *list)
{
    DoubleLinkedListNode *node = list->head;
    return node != NULL ? list_remove(list, node) : NULL;
}

void *list_remove(DoubleLinkedList *list, DoubleLinkedListNode *node)
{
    void *result = NULL;
    check(list->head && list->tail, "List is empty!");
    check(node, "node can't be NULL");

    if (node == list->head && node == list->tail)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else if (node == list->head)
    {
        list->head = node->next;
        check(list->head != NULL, "Invalid list, somehow got a head that is NULL.");
        list->head->prev = NULL;
    }
    else if (node == list->tail)
    {
        list->tail = node->next;
        check(list->tail != NULL, "Invalid list, somehow got a tail that is NULL.");
        list->tail->next = NULL;
    }
    else
    {
        DoubleLinkedListNode *after = node->next;
        DoubleLinkedListNode *before = node->prev;
        after->prev = before;
        before->next = after;
    }

    list->count--;
    result = node->val;
    free(node);

error:
    return;
}