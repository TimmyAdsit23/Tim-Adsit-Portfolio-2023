// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest36.c
// =========================
// Unit test for listyWeave(): listy2 is non-NULL empty string.


#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "ListyString.h"

int listyEquals(ListyString *listy, char *str)
{
	int i, length = strlen(str), success = 1;
	ListyNode *temp = listy->head;

	// Check contents of listy.
	for (i = 0; i < length; i++)
	{
		assert(temp->data == str[i]);
		temp = temp->next;
	}

	// Check for proper NULL termination of listy.
	assert(temp == NULL);

	// Check length variable in listy.
	assert(listy->length == length);

	return success;
}

int unit_test(int argc, char **argv)
{
	ListyString *listy1;
	ListyString *listy2;
	ListyString *retval;

	// Pointers to original nodes in listy1. These should not change.
	ListyNode *originalNodesL1[3];

	listy1 = createListyString("Hi!");
	listy2 = createListyString("");

	originalNodesL1[0] = listy1->head;
	originalNodesL1[1] = listy1->head->next;
	originalNodesL1[2] = listy1->head->next->next;

	retval = listyWeave(listy1, listy2);

	// Print (mainly for debugging purposes).
	printListyString(listy1);
	printListyString(listy2);
	printListyString(retval);

	// Check contents of listy1.
	assert(listyEquals(listy1, "Hi!"));

	// Check contents of listy2.
	assert(listyEquals(listy2, ""));

	// Check return value of listyWeave().
	assert(retval == listy1);

	// Check that the original nodes in listy1 are still intact.
	assert(originalNodesL1[0] == listy1->head);
	assert(originalNodesL1[1] == listy1->head->next);
	assert(originalNodesL1[2] == listy1->head->next->next);

	printf("Hooray!\n");

	return 0;
}
