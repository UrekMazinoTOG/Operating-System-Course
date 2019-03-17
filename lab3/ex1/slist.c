#include "slist.h"

node* init(T val)
{
    // 1 Allocate a new node
    node* head = (node*)malloc(sizeof(node));
    // Check error of malloc()
    if(head == NULL) 
    {
        perror("Out of memory!\n");
        exit(EXIT_FAILURE);
    }
    // 2 Set data of a new node
    head->data = val;
    head->next = NULL;

    return head;
}

node* deal(node* head)
{
    while(head != NULL) head = pop_front(head);
    return head;
}

node* push_front(node* head, T val)
{
    // 1 Create the new node
    node* newNode = init(val);
    // 2 Link the new node to the head node
    newNode->next = head;
    
    return newNode;
}
node* insert(node *head, T val, size_t pos)
{
    assert(pos <= size(head) && "IndexOutOfBoundsException");
    // Special case : pos == 0
    if(pos == 0) return push_front(head, val);

    // 1 Create the new node
    node* newNode = init(val);
    // 2 Find the position to insert
    node* pNode = head;
    while(--pos) pNode = pNode->next;
    // 3 Link the new node to the Q node
    newNode->next = pNode->next;
    // 4 Link the P node to the new node
    pNode->next = newNode;

    return head;
}

node* pop_front(node* head)
{
    if(head == NULL) return NULL;
    // 1 Save the next node of head
    node* newHead = head->next;
    // 2 Deallocate storage space of node
    free(head);
    // 3 Return the pointer to the new head
    return newHead;
}

node* delete(node *head, size_t pos)
{
    assert(pos < size(head) && "IndexOutOfBoundsException");
    // Special case : pos == 0
    if(pos == 0) return pop_front(head);

    // 1 Find the position to insert
    node* pNode = head;
    while(--pos) pNode = pNode->next;
    // 2 Save the pointer point to the delete node
    node* dltNode = pNode->next;
    // 3 Link the P node to the Q.next node
    pNode->next = dltNode->next;
    // 4 Link the P node to the new node
    free(dltNode);

    return head;
}

size_t size(node *head)
{
    // List is empty
    if(head == NULL) return 0;
    // Count the node of list
    register size_t lstSize = 0;
    while(head != NULL) 
    {
        head = head->next;
        lstSize = lstSize + 1;
    }

    return lstSize;
}
