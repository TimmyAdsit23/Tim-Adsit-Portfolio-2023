// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest42.c
// =========================
// Unit test for listyCmp(): Test the comparison of two empty strings.


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	ListyString *listy1, *listy2;

	// Create an empty string.
	listy1 = malloc(sizeof(ListyString));
	listy1->head = NULL;
	listy1->length = 0;

	// Create another empty string.
	listy2 = malloc(sizeof(ListyString));
	listy2->head = NULL;
	listy2->length = 0;

	assert(listyCmp(listy1, listy2) == 0);

	printf("Hooray!\n");

	return 0;
}
