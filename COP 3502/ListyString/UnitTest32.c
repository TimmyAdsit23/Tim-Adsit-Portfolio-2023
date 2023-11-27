// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest32.c
// =========================
// Unit test for stringWeave(): listy is NULL and str is non-empty.


#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int i, length;
	char *result = "weaver";

	ListyNode *temp;
	ListyString *listy = NULL;

	length = strlen(result);

	listy = stringWeave(listy, "weaver");

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

	printf("Hooray!\n");

	return 0;
}
