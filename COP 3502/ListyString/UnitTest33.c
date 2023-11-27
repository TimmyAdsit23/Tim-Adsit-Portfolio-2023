// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest33.c
// =========================
// Unit test for listyWeave(): Both strings are of equal length.


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

	// Pointers to original nodes in listy1 and Listy2. These should not change.
	ListyNode *originalNodesL1[6];
	ListyNode *originalNodesL2[6];

	listy1 = createListyString("Hlotee");
	listy2 = createListyString("el hr!");

	originalNodesL1[0] = listy1->head;
	originalNodesL1[1] = listy1->head->next;
	originalNodesL1[2] = listy1->head->next->next;
	originalNodesL1[3] = listy1->head->next->next->next;
	originalNodesL1[4] = listy1->head->next->next->next->next;
	originalNodesL1[5] = listy1->head->next->next->next->next->next;

	originalNodesL2[0] = listy2->head;
	originalNodesL2[1] = listy2->head->next;
	originalNodesL2[2] = listy2->head->next->next;
	originalNodesL2[3] = listy2->head->next->next->next;
	originalNodesL2[4] = listy2->head->next->next->next->next;
	originalNodesL2[5] = listy2->head->next->next->next->next->next;

	retval = listyWeave(listy1, listy2);

	// Print (mainly for debugging purposes).
	printListyString(listy1);
	printListyString(listy2);
	printListyString(retval);

	// Check contents of listy1.
	assert(listyEquals(listy1, "Hello there!"));

	// Check contents of listy2.
	assert(listyEquals(listy2, "el hr!"));

	// Check return value of listyWeave().
	assert(retval == listy1);

	// Check that the original nodes in listy1 are still intact.
	assert(originalNodesL1[0] == listy1->head);
	assert(originalNodesL1[1] == listy1->head->next->next);
	assert(originalNodesL1[2] == listy1->head->next->next->next->next);
	assert(originalNodesL1[3] == listy1->head->next->next->next->next->next->next);
	assert(originalNodesL1[4] == listy1->head->next->next->next->next->next->next->next->next);
	assert(originalNodesL1[5] == listy1->head->next->next->next->next->next->next->next->next->next->next);

	// Check that the original nodes in listy2 are still intact.
	assert(originalNodesL2[0] == listy2->head);
	assert(originalNodesL2[1] == listy2->head->next);
	assert(originalNodesL2[2] == listy2->head->next->next);
	assert(originalNodesL2[3] == listy2->head->next->next->next);
	assert(originalNodesL2[4] == listy2->head->next->next->next->next);
	assert(originalNodesL2[5] == listy2->head->next->next->next->next->next);

	printf("Hooray!\n");

	return 0;
}
