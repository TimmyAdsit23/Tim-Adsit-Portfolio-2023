// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest02.c
// =========================
// Test of createListyString().


#include <assert.h>
#include <stdio.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	ListyString *l1, *l2, *l3;

	l1 = createListyString("~ ");

	assert(l1->head->data == '~');
	assert(l1->head->next->data == ' ');
	assert(l1->head->next->next == NULL);
	assert(l1->length == 2);

	l2 = createListyString(NULL);

	assert(l2 != NULL);
	assert(l2->head == NULL);
	assert(l2->length == 0);

	l3 = createListyString("");

	assert(l3 != NULL);
	assert(l3->head == NULL);
	assert(l3->length == 0);

	printf("Hooray!\n");

	return 0;
}
