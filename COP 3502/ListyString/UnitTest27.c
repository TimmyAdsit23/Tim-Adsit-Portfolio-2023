// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest27.c
// =========================
// Unit test for stringWeave(): Both strings are of equal length.


#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int i, length;
	char *result = "Hello there!";

	ListyNode *temp;
	ListyString *listy;
	ListyString *retval;

	// Pointers to original nodes in listy. These should not change.
	ListyNode *originalNodes[6];

	length = strlen(result);

	listy = createListyString("Hlotee");
	originalNodes[0] = listy->head;
	originalNodes[1] = listy->head->next;
	originalNodes[2] = listy->head->next->next;
	originalNodes[3] = listy->head->next->next->next;
	originalNodes[4] = listy->head->next->next->next->next;
	originalNodes[5] = listy->head->next->next->next->next->next;
	retval = stringWeave(listy, "el hr!");

	// Print (mainly for debugging purposes).
	printListyString(listy);

	// Check contents of linked list.
	temp = listy->head;
	for (i = 0; i < length; i++)
	{
		assert(temp->data == result[i]);
		temp = temp->next;
	}

	// Check for proper NULL termination of linked list.
	assert(temp == NULL);

	// Check length variable.
	assert(listy->length == length);

	// Check return value of stringWeave().
	assert(retval == listy);

	// Check that the original nodes are still intact.
	assert(originalNodes[0] == listy->head);
	assert(originalNodes[1] == listy->head->next->next);
	assert(originalNodes[2] == listy->head->next->next->next->next);
	assert(originalNodes[3] == listy->head->next->next->next->next->next->next);
	assert(originalNodes[4] == listy->head->next->next->next->next->next->next->next->next);
	assert(originalNodes[5] == listy->head->next->next->next->next->next->next->next->next->next->next);

	printf("Hooray!\n");

	return 0;
}
