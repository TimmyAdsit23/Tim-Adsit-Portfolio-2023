// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest39.c
// =========================
// Unit test for listyCmp(): Test the comparison of two equivalent, non-empty
// strings.


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	ListyString *listy1, *listy2;

	// Manually create a listy string. This is awful.
	listy1 = malloc(sizeof(ListyString));
	listy1->head = malloc(sizeof(ListyNode));
	listy1->head->next = malloc(sizeof(ListyNode));
	listy1->head->next->next = malloc(sizeof(ListyNode));
	listy1->head->next->next->next = NULL;
	listy1->head->data = 'c';
	listy1->head->next->data = 'a';
	listy1->head->next->next->data = 't';
	listy1->length = 3;

	// Manually create another listy string. This is awful.
	listy2 = malloc(sizeof(ListyString));
	listy2->head = malloc(sizeof(ListyNode));
	listy2->head->next = malloc(sizeof(ListyNode));
	listy2->head->next->next = malloc(sizeof(ListyNode));
	listy2->head->next->next->next = NULL;
	listy2->head->data = 'c';
	listy2->head->next->data = 'a';
	listy2->head->next->next->data = 't';
	listy2->length = 3;

	assert(listyCmp(listy1, listy2) == 0);

	printf("Hooray!\n");

	return 0;
}
