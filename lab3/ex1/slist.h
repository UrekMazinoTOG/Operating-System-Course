#if !defined(SINGLE_LINKED_LIST_H)
#define SINGLE_LINKED_LIST_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>

// Data type of list
typedef uint64_t T;
// Define node struct
typedef struct node
{
    T data;
    struct node* next;
} node;

// function to initialize a node
node* init(T val);
node* deal(node *head);
// function to insert the new node into the slist
node* push_front(node* head, T val);
node* insert(node *head, T val, size_t pos);
// function to remove the node of the slist
node* pop_front(node* head);
node* delete(node *head, T val);
// function to check size of the slist
size_t size(node *head);

#endif // SINGLE_LINKED_LIST_H
