// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest48.c
// =========================
// Unit test for printListyString(): Test the printing of an empty string.


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

	printListyString(listy);
	printf("Length: %d\n", listyLength(listy));

	return 0;
}
