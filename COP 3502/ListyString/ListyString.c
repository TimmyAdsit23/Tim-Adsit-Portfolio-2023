// Tim Adsit
// COP 3502, Spring 2023
// ti047614

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"


int processInputFile(char *filename);

ListyString *createListyString(char *str);

ListyNode *createListyNodeAtHead(char data, ListyNode *oldHead);

ListyNode *createListyNode(char data, ListyNode *next);

ListyString *destroyListyString(ListyString *listy);

void destroyListyNode(ListyNode *node);

char *getListyStringsString(ListyString *listy);

ListyNode *getListyNode(ListyNode *node, int n);

ListyString *cloneListyString(ListyString *listy);

ListyString *listyCat(ListyString *listy, char *str);

ListyString *listyCharCat(ListyString *listy, char c);

ListyNode *getEndNode(ListyString *listy);

ListyNode *getEndNode2(ListyNode *node);

ListyString *listyPrepend(ListyString *listy, char *str);

void replaceChar(ListyString *listy, char key, char *str);

void actuallyPrintRecursive(ListyNode *node);

void printListyString(ListyString *listy);

void actuallyPrint(ListyNode *node);

void listyCensor(ListyString *listy, char *badChars);

void censor(ListyNode *node, int *ASCII);

void reverseListyString(ListyString *listy);

void print_string_backwards(ListyString *listy, ListyNode *node);

ListyString *print_string_backwards2(ListyString *listy, ListyNode *node);

ListyString *stringWeave(ListyString *listy, char *str);

void weave(ListyNode *node, char *str);

ListyString *listyWeave(ListyString *listy1, ListyString *listy2);

void weaveListy(ListyNode *node1, ListyNode *node2);

int listyCmp(ListyString *listy1, ListyString *listy2);

int listyCmpRecursive(ListyNode *node1, ListyNode *node2);

int charCount(ListyString *listy, char key);

int charCountRecursive(ListyNode *node, char key, int count);

int listyLength(ListyString *listy);

double difficultyRating(void);

double hoursSpent(void);


/*
==================================================================
*/

int main(int argc, char **argv)
{
    char *fileName = argv[0];
    processInputFile(fileName);

    return 0;
}

/*
==================================================================
*/

int processInputFile(char *filename)
{
    FILE *ifp = fopen(filename, "r");
    ListyString *string;
    char currentChar, command, key;
    char str[1024];
    int counter = 0;

    if (ifp == NULL)
        return 1;

    string = createListyString("");
    currentChar = fgetc(ifp);
    

    // getting the string
    while (currentChar != '\n')
    {
        listyCharCat(string, currentChar);
        currentChar = fgetc(ifp);
    }
    // ends with '\n'

    currentChar = fgetc(ifp); // gets command
    
    // runs until the end of file
    while (currentChar != EOF)
    {
        currentChar = fgetc(ifp); // this is a space
        command = currentChar;

        if (command == '@')
        {
            currentChar = fgetc(ifp); // the key
            key = currentChar;
            currentChar = fgetc(ifp); // this is a space
            currentChar = fgetc(ifp); // 1st letter of str

            while(currentChar != '\n')
            {
                str[counter++] = currentChar;
                currentChar = fgetc(ifp); // letters of str
            }
            // currentChar ends with \n

            replaceChar(string, key, str);
        }
        else if (command == '>')
        {
            while(currentChar != '\n')
            {
                str[counter++] = currentChar;
                currentChar = fgetc(ifp); // letters of str
            }
            // currentChar ends with \n

            listyCat(string, str);
        }
        else if (command == '<')
        {
            while(currentChar != '\n')
            {
                str[counter++] = currentChar;
                currentChar = fgetc(ifp); // letters of str
            }
            // currentChar ends with \n

            listyPrepend(string, str);
        }
        else if (command == '~')
        {
            reverseListyString(string);
        }
        else if (command == '*')
        {
            while (currentChar != '\n')
            {
                str[counter++] = currentChar;
                currentChar = fgetc(ifp); // letters of str
            }
            // currentChar ends with \n

            listyCensor(string, str);
        }
        else if (command == '-')
        {
            currentChar = fgetc(ifp); // the key
            key = currentChar;
            currentChar = fgetc(ifp); // this is a space

            replaceChar(string, key, "");
        }
        else if (command == '&')
        {
            while (currentChar != '\n')
            {
                str[counter++] = currentChar;
                currentChar = fgetc(ifp); // letters of str
            }
            // currentChar ends with \n

            stringWeave(string, str);
        }
        else if (command == '#')
        {
            currentChar = fgetc(ifp); // the key
            key = currentChar;
            currentChar = fgetc(ifp); // this is a space

            printf("%d\n", charCount(string, key));
        }
        else if (command == '?')
        {
            printf("%d\n", string->length);
        }
        else if (command == '!')
        {
            printListyString(string);
        }

        // current char ends with the '\n'
        currentChar = fgetc(ifp); // gets command
    }
    
    return 0;
}

ListyNode *createListyNodeAtHead(char data, ListyNode *oldHead)
{
    ListyNode *brandNewNode = malloc(sizeof(ListyNode));
    brandNewNode->data = data;
    brandNewNode->next = oldHead;
    return brandNewNode;
}

ListyNode *createListyNode(char data, ListyNode *next)
{
    ListyNode *brandNewNode = malloc(sizeof(ListyNode));
    brandNewNode->data = data;
    brandNewNode->next = next;
    return brandNewNode;
}

ListyString *headInsert(char *str, ListyString *listy)
{
    int i, length = strlen(str);
    ListyNode *newHead;
    for(i = length-1; i >= 0; i--)
    {
        // new->head is initially NULL, so the last node will point to NULL
        newHead = createListyNodeAtHead(str[i], listy->head);
        listy->head = newHead;
        listy->length++;
    }

    return listy;
}

ListyString *createListyString(char *str)
{
    ListyString *new = malloc(sizeof(ListyString));
    
    int length;

    new->head = NULL;
    new->length = 0;

    if(str == NULL || strcmp("", str) == 0)
        return new;

    length = strlen(str);

    // head insert

    // new->head = createListyNodeAtHead(str[i++], NULL);    
    
    return headInsert(str, new);
}

ListyString *destroyListyString(ListyString *listy)
{
    if (listy == NULL || listy->head == NULL)
        return NULL;

    destroyListyNode(listy->head);
    free(listy);

    return NULL;
}

void destroyListyNode(ListyNode *node)
{
    if(node == NULL)
        return;

    destroyListyNode(node->next);
    free(node);
}

char *getListyStringsString(ListyString *listy)
{
    int i;
    printf("poo->length: %d\n", listy->length);

    char *str = malloc(sizeof(char) * (listy->length));


    if(listy == NULL)
        return NULL;


    if(listy->head == NULL)
        return NULL;


    for(i = 0; i < listy->length; i++)
    {
        str[i] = getListyNode(listy->head, i)->data;
    }

    return str;
}

ListyNode *getListyNode(ListyNode *node, int n)
{
    printf("n: %d\n", n);
    fflush(stdout);
    if(n == 0 || node->next == NULL)
    {
        printf("returning from getListyNode...\n");
        fflush(stdout);
        return node;
    }

    printf("calling getListyNode again...\n");
    fflush(stdout);

    return getListyNode(node->next, n-1);
}

ListyNode *searchListy(ListyNode *node, char key)
{
    // base case, if we have reached the last element in the ListyString

    if (node->next == NULL)
        return NULL;
    
    // return the next node that has the key in its data so that we know the node to change the next
    // of.
    if(node->next->data == key)
    {
        return node;
    }
    
    return searchListy(node->next, key);
}

ListyString *cloneListyString(ListyString *listy)
{
    if(listy == NULL)
        return NULL;

    if(listy->head == NULL)
        return createListyString(NULL);
    
    char *str;
    str = getListyStringsString(listy);

    if(str == NULL)
    {
        printf("str was not copied over correctly\nline: %d\n", __LINE__);
        return NULL;
    }

    printf("listy successfully cloned\n");
    return createListyString(str);
}

ListyString *listyCat(ListyString *listy, char *str)
{
    if(listy == NULL && str == NULL)
        return NULL;
    
    if(listy == NULL && strcmp("", str) == 0)
        return createListyString(str);
    
    if(listy == NULL && strcmp("", str) != 0)
        return createListyString(str);

    // make a new ListyString with the data, then free the new ListyString leaving the data intact
    ListyString *new = createListyString(str);
    ListyNode *headOfNew = new->head, *tailOfOld = getEndNode(listy);

    tailOfOld->next = headOfNew;

    listy->length += strlen(str);

    free(new);

    return listy;
}

ListyString *listyCharCat(ListyString *listy, char c)
{
    if(listy == NULL)
        return NULL;

    ListyNode *tailOfOld = getEndNode(listy);


    ListyNode *new = malloc(sizeof(ListyNode));
    new->data = c;
    new->next = NULL;

    if(tailOfOld == NULL)
    {
        tailOfOld = new;
        listy->head = new;
        printf("new head!\n");
    }
    else
    {
        tailOfOld->next = new;
    }

    listy->length++;

    return listy;
}

ListyNode *getEndNode(ListyString *listy)
{
    return getEndNode2(listy->head);
}

ListyNode *getEndNode2(ListyNode *node)
{
    if(node == NULL)
        return NULL;
    if(node->next == NULL)
        return node;
    
    return getEndNode2(node->next);
}

ListyString *listyPrepend(ListyString *listy, char *str)
{
    if(listy == NULL && str == NULL)
        return NULL;
    
    if(listy == NULL && strcmp("", str) == 0)
        return createListyString(str);

    if(listy == NULL && strcmp("", str) != 0)
        return createListyString(str);

    // make a new ListyString with the data, then free the old ListyString leaving the data intact
    ListyString *new = createListyString(str);
    ListyNode *headOfOld = listy->head, *tailOfNew = getEndNode(new);

    tailOfNew->next = headOfOld;

    new->length += strlen(str);

    free(listy);

    return new;
}

void replaceChar(ListyString *listy, char key, char *str)
{
    //If listy is NULL, or if listy→head is NULL, simply return.
    if(listy == NULL || listy->head == NULL)
        return;


    ListyString *new;
    ListyNode *newHead, *newTail, *previousNode, *searchingNode = listy->head;
    int counter = 0;
    
    //If str is NULL or the empty string (“”), this function simply removes
    //all instances of key from the linked list.

    if(str == NULL || strcmp(str, "") == 0)
    {
        previousNode = searchListy(searchingNode, key);

        while(previousNode != NULL)
        {
            // cut out the key
            previousNode->next = previousNode->next->next;

            // we no longer need the node with the key
            free(previousNode->next);

            // this is now what was previously previousNode->next->next
            searchingNode = previousNode->next;

            // finds a node where the next node contains the key
            previousNode = searchListy(searchingNode, key);
        }
        return;
    }


    if(listy->head->data == key)
    {
        // could be a struct? idk if we can make them
        new = createListyString(str);
        newHead = new->head;
        newTail = getEndNode(new);

        newTail->next = listy->head->next;
        free(listy->head);
        listy->head = newHead;
        searchingNode = newHead;
        free(new);
    }

    previousNode = searchListy(searchingNode, key);


    while(previousNode != NULL)
    {
        printf("Counter: %d\n", counter++);
        // makes new listyString
        new = createListyString(str);
        newHead = new->head;
        newTail = getEndNode(new);


        // the next node from the node with the key is the new next of the newTail
        if(previousNode->next->next != NULL)
        {
            newTail->next = previousNode->next->next;
        }
        else
        {
            newTail->next = NULL;
        }
            

        

        free(previousNode->next);

        previousNode->next = newHead;



        searchingNode = newTail;

        // finds a node where the next node contains the key
        previousNode = searchListy(searchingNode, key);


        // now that we have used our new ListyString for the nodes, we can discard the ListyString
        // object
        free(new);
        listy->length += strlen(str) - 1;
    }

    ListyNode *lastNode = getEndNode(listy);
    printf("lastNode: %c\n", lastNode->data);

    if(lastNode->next==NULL)
        printf("lastNode->next: NULL\n");

}

void actuallyPrintRecursive(ListyNode *node)
{
    if(node == NULL)
        return;



    printf("%c", node->data);
    actuallyPrintRecursive(node->next);
}

void printListyString(ListyString *listy)
{
    actuallyPrint(listy->head);
}

void actuallyPrint(ListyNode *node)
{
    if(node == NULL)
        return;
    actuallyPrintRecursive(node);
    printf("\n");
}

void listyCensor(ListyString *listy, char *badChars)
{
    if(badChars == NULL || strcmp(badChars, "") == 0 || listy == NULL || listy->head == NULL)
        return;
    int ASCII[256];
    int i, length = strlen(badChars);
    for(i = 0; i < length; i++)
    {
        ASCII[badChars[i]]++;
    }
    censor(listy->head, ASCII);
}

void censor(ListyNode *node, int *ASCII)
{
    if(node == NULL)
        return;

    if(ASCII[node->data])
        node->data = '*';
    
    censor(node->next, ASCII);
}

// doesnt work
void reverseListyString(ListyString *listy)
{
    ListyString *new = createListyString(""), *new2;
    

    new2 = print_string_backwards2(new, listy->head);

    listy = new2;
}

void print_string_backwards(ListyString *listy, ListyNode *node)
{
    if(node == NULL)
        return; 

    print_string_backwards(listy, node->next);

    listy = listyCharCat(listy, node->data);
}

ListyString *print_string_backwards2(ListyString *listy, ListyNode *node)
{
    print_string_backwards(listy, node);

    return listy;
}

ListyString *stringWeave(ListyString *listy, char *str)
{
    if(listy == NULL && str == NULL)
        return NULL;
    else if(listy == NULL && str != NULL)
        return createListyString(str);
    else if(listy == NULL && strcmp(str, "") == 0)
        return createListyString("");
    
    weave(listy->head, str);

    return listy;
}

void weave(ListyNode *node, char *str)
{
    if(node->next == NULL && str[1] != '\0')
    {
        node->next = createListyNode(str[0], NULL);
        weave(node->next->next, &str[1]);
    }
    else if(node != NULL && str[0] == '\0')
    {
        return;
    }
    else if(node != NULL && str[0] != '\0')
    {
        node->next = createListyNode(str[0], node->next);
        weave(node->next->next, &str[1]);
        return;
    }

    return;
}

ListyString *listyWeave(ListyString *listy1, ListyString *listy2)
{
    if(listy1 == NULL && listy2 == NULL)
        return NULL;
    else if(listy1 == NULL && listy2 != NULL)
        return listy2;
    else if(listy1 == NULL && listy2->head == NULL)
        return listy2;
    
    weaveListy(listy1->head, listy2->head);

    return listy1;
}

void weaveListy(ListyNode *node1, ListyNode *node2)
{
    if(node1->next == NULL && node2->next != NULL)
    {
        node1->next = createListyNode(node2->data, NULL);
        weaveListy(node1->next->next, node2->next);
    }
    else if(node1 != NULL && node2 == NULL)
    {
        return;
    }
    else if(node1 != NULL && node2 != NULL)
    {
        node1->next = createListyNode(node2->data, node1->next);
        weaveListy(node1->next->next, node2->next);
        return;
    }

    return;
}

int listyCmp(ListyString *listy1, ListyString *listy2)
{
    if (listy1 == NULL && listy2 == NULL)
        return 0;

    return listyCmpRecursive(listy1->head, listy2->head);
}

int listyCmpRecursive(ListyNode *node1, ListyNode *node2)
{
    if (node1 == NULL && node2 == NULL)
        return 0;
    else if (node1 != NULL && node2 == NULL)
        return 1;
    else if (node1 == NULL && node2 == NULL)
        return 1;
    else if (node1->data != node2-> data)
        return 1;

    return listyCmpRecursive(node1->next, node2->next);
}

int charCount(ListyString *listy, char key)
{
    int count = 0;
    if (listy == NULL)
        return -1;
    else if (listy->head == NULL)
        return 0;
    
    return charCountRecursive(listy->head, key, count);
}

int charCountRecursive(ListyNode *node, char key, int count)
{
    if(node == NULL)
        return count;
    
    if(node->data == key)
    {
        charCountRecursive(node->next, key, count++);
    }

    charCountRecursive(node->next, key, count);
    return count;
}

int listyLength(ListyString *listy)
{
    return listy->length;
}

double difficultyRating(void)
{
    return 4.25;
}

double hoursSpent(void)
{
    return 15;
}

