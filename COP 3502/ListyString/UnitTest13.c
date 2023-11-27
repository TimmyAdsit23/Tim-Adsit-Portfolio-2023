// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest13.c
// =========================
// Unit test for listyPrepend(): Test prepending of a NULL string to an empty
// ListyString.


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	ListyString *listy;
	ListyString *retval;

	// Create empty string.
	listy = malloc(sizeof(ListyString));
	listy->head = NULL;
	listy->length = 0;

	retval = listyPrepend(listy, NULL);

	assert(listy == retval);
	assert(listy->head == NULL);
	assert(listy->length == 0);

	printf("Hooray!\n");

	return 0;
}
