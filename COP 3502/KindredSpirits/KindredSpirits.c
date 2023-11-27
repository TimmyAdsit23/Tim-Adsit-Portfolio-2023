#include <stdio.h>
#include <stdlib.h>
#include "KindredSpirits.h"

typedef struct linkedNode
{
    int data;
    struct linkedNode *next;
    struct linkedNode *tail;
} linkedNode;

int isReflection(node *a, node *b);

node *makeReflection(node *root);

int kindredSpirits(node *a, node *b);

double difficultyRating(void);

double hoursSpent(void);

//=================
// helper functions
//=================

node *makeNode(int data);

node *makeReflectionRecursion(node *root, node *newHead);

void printInOrderTraversal(node *root);

void printPreOrderTraversal(node *root);

void printPostOrderTraversal(node *root);

void printLinkedList(linkedNode *root);

linkedNode *linkedPreOrderTraversal(node *root);

linkedNode *linkedPostOrderTraversal(node *root);

int compareLinkedList(linkedNode *headA, linkedNode *headB);

linkedNode *makeLinkedNode(int datum);

int countPostOrderTraversal(node *root, int count);

int findLengthOfBT(node *root);

void addPostOrderTraversal(node *root, linkedNode *head);

void addToEnd(linkedNode *head, linkedNode *new);

linkedNode *linkedPreOrderTraversal(node *root);

void addPreOrderTraversal(node *root, linkedNode *head);

//==========
// functions
//==========

int isReflection(node *a, node *b)
{
    if (a == NULL && b == NULL)
        return 1;
    else if (a == NULL && b != NULL)
        return 0;
    else if (b == NULL && a != NULL)
        return 0;

    if (a->data == b->data && isReflection(a->left, b->right) && isReflection(b->left, a->right))
        return 1;
}

node *makeReflection(node *root)
{
    node *newHead;

    newHead = makeReflectionRecursion(root, newHead);

    return newHead;
}

node *makeReflectionRecursion(node *root, node *newHead)
{
    node *newNode;

    if (root == NULL)
        return NULL;

    newNode = makeNode(root->data);
    newHead = newNode;

    newHead->left = makeReflectionRecursion(root->right, newHead->left);

    newHead->right = makeReflectionRecursion(root->left, newHead->right);

    return newNode;
}

int kindredSpirits(node *a, node *b)
{
    linkedNode *postHeadA, *preHeadA, *postHeadB, *preHeadB;

    postHeadA = linkedPostOrderTraversal(a);
    postHeadB = linkedPostOrderTraversal(b);

    preHeadA = linkedPreOrderTraversal(a);
    preHeadB = linkedPreOrderTraversal(b);

    if (compareLinkedList(postHeadA, preHeadB))
    {
        return 1;
    }
    else if (compareLinkedList(postHeadB, preHeadA))
    {
        return 1;
    }

    return 0;
}

double difficultyRating(void)
{
    return 2.5;
}

double hoursSpent(void)
{
    return 12;
}

//=================
// helper functions
//=================

node *makeNode(int datum)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = datum;
    return newNode;
}

// create a linked list in a post order traversal pattern of a binary tree
linkedNode *linkedPostOrderTraversal(node *root)
{
    int count = 0;
    linkedNode *array, *stupidValueICantFix;
    count = findLengthOfBT(root);

    array = malloc(sizeof(linkedNode) * count);
    addPostOrderTraversal(root, array);

    stupidValueICantFix = array;
    array = array->next;

    free(stupidValueICantFix);

    return array;
}

// create a linked list in a post order traversal pattern of a binary tree
linkedNode *linkedPreOrderTraversal(node *root)
{
    int count = 0;
    linkedNode *array, *stupidValueICantFix;
    count = findLengthOfBT(root);

    array = malloc(sizeof(linkedNode) * count);
    addPreOrderTraversal(root, array);

    stupidValueICantFix = array;
    array = array->next;
    free(stupidValueICantFix);

    return array;
}

void addPostOrderTraversal(node *root, linkedNode *head)
{
    if (root == NULL)
        return;

    addPostOrderTraversal(root->left, head);

    addPostOrderTraversal(root->right, head);

    addToEnd(head, makeLinkedNode(root->data));
}

void addPreOrderTraversal(node *root, linkedNode *head)
{
    if (root == NULL)
        return;

    addToEnd(head, makeLinkedNode(root->data));

    addPreOrderTraversal(root->left, head);

    addPreOrderTraversal(root->right, head);
}

void addToEnd(linkedNode *head, linkedNode *new)
{
    linkedNode *placeHolder = head;

    while (placeHolder->next != NULL)
    {
        placeHolder = placeHolder->next;
    }

    placeHolder->next = new;
}

int countPostOrderTraversal(node *root, int count) // left, right, root
{
    if (root == NULL)
        return count;

    count = countPostOrderTraversal(root->left, count);

    count = countPostOrderTraversal(root->right, count);

    return count + 1;
}

int findLengthOfBT(node *root)
{
    int count = 0;

    count = countPostOrderTraversal(root, count);
    return count;
}

// compare two linked lists, return 1 if same, 0 if not
int compareLinkedList(linkedNode *headA, linkedNode *headB)
{
    linkedNode *trackerA, *trackerB;
    trackerA = headA;
    trackerB = headB;

    while (trackerA != NULL && trackerB != NULL)
    {
        if (trackerA->data != trackerB->data)
        {
            // linked lists not the same
            return 0;
        }
        trackerA = trackerA->next;
        trackerB = trackerB->next;
    }
    // linked lists the same
    return 1;
}

linkedNode *makeLinkedNode(int datum)
{
    linkedNode *newLinkedNode = malloc(sizeof(linkedNode));
    newLinkedNode->data = datum;
    return newLinkedNode;
}
