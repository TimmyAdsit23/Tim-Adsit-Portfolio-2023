// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest26.c
// =========================
// Unit test for reverseListyString(): Test the reversal of an empty string.
// This essentially just checks whether there is a preventable segfault.


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	// Set up an empty string.
	ListyString *listy = malloc(sizeof(ListyString));
	listy->head = NULL;
	listy->length = 0;

	reverseListyString(listy);

	assert(listy->head == NULL);
	assert(listy->length == 0);

	printf("Hooray!\n");

	return 0;
}
