// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest16.c
// =========================
// Unit test for replaceChar(): Test the replacement of a single character
// with the empty string.


#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int i, length;
	char *result = "hello";

	ListyNode *temp;
	ListyString *listy;

	length = strlen(result);

	listy = createListyString("hello!");
	replaceChar(listy, '!', "");

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
