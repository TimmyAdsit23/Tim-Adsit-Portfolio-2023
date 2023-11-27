// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest03.c
// =========================
// Basic test of destroyListyString(). This does not guarantee memory is being
// freed correctly, but it does check for preventable segmentation faults.


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	ListyString *l1;

	l1 = createListyString("Hi");
	l1 = destroyListyString(l1);
	assert(l1 == NULL);

	l1 = malloc(sizeof(ListyString));
	l1->head = NULL;
	l1->length = 0;
	l1 = destroyListyString(l1);
	assert(l1 == NULL);

	l1 = NULL;
	l1 = destroyListyString(l1);
	assert(l1 == NULL);

	printf("Hooray!\n");

	return 0;
}
