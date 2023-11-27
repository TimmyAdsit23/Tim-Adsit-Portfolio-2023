// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest37.c
// =========================
// Unit test for listyWeave(): listy1 is empty string and listy2 is non-empty.


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
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

	// Create an empty string.
	listy1 = malloc(sizeof(ListyString));
	listy1->head = NULL;
	listy1->length = 0;

	listy2 = createListyString("weaver");

	retval = listyWeave(listy1, listy2);

	// Print (mainly for debugging purposes).
	printListyString(listy1);
	printListyString(listy2);
	printListyString(retval);

	// Check contents of listy1.
	assert(listyEquals(listy1, "weaver"));

	// Check contents of listy2.
	assert(listyEquals(listy2, "weaver"));

	// Check return value of listyWeave().
	assert(retval == listy1);

	printf("Hooray!\n");

	return 0;
}
