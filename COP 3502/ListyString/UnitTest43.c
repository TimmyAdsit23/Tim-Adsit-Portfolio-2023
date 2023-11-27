// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest43.c
// =========================
// Unit test for listyCmp(): Test the comparison of a NULL pointer to an empty
// string.


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	ListyString *listy;

	// Create an empty string.
	listy = malloc(sizeof(ListyString));
	listy->head = NULL;
	listy->length = 0;

	assert(listyCmp(listy, NULL) != 0);
	assert(listyCmp(NULL, listy) != 0);

	printf("Hooray!\n");

	return 0;
}
