// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest44.c
// =========================
// Unit test for charCount(): Test with an empty string.


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

	printf("'x' count: %d\n", charCount(listy, 'x'));
	printf("'r' count: %d\n", charCount(listy, 'r'));
	printf("' ' count: %d\n", charCount(listy, ' '));
	printf("'\\0' count: %d\n", charCount(listy, '\0'));

	return 0;
}
