// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest06.c
// =========================
// Unit test for listyCat(): Test concatenation of a non-empty string to an
// empty ListyString.


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int i, length;
	char *result = "Hewwo!";

	ListyNode *temp;
	ListyString *listy;
	ListyString *retval;

	length = strlen(result);

	// Create empty string.
	listy = malloc(sizeof(ListyString));
	listy->head = NULL;
	listy->length = 0;

	retval = listyCat(listy, "Hewwo!");

	assert(listy == retval);

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
