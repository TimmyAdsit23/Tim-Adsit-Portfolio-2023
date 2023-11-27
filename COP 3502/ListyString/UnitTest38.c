// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest38.c
// =========================
// Unit test for listyWeave(): listy is NULL and str is non-empty.


#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "ListyString.h"

int listyEquals(ListyString *listy, char *str)
{
	int i, length = strlen(str), success = 1;
	ListyNode *temp = listy->head;

	// Check contents of listy.
	for (i = 0; i < length; i++)
	{
		assert(temp->data == str[i]);
		temp = temp->next;
	}

	// Check for proper NULL termination of listy.
	assert(temp == NULL);

	// Check length variable in listy.
	assert(listy->length == length);

	return success;
}

int unit_test(int argc, char **argv)
{
	ListyString *listy1 = NULL;
	ListyString *listy2;

	listy2 = createListyString("weaver");
	listy1 = listyWeave(listy1, listy2);

	// Print (mainly for debugging purposes).
	printListyString(listy1);
	printListyString(listy2);

	// Check contents of listy1.
	assert(listyEquals(listy1, "weaver"));

	// Check contents of listy2.
	assert(listyEquals(listy1, "weaver"));

	// Ensure listy1 isn't just the same pointer as listy2.
	assert(listy1 != listy2);

	// Ensure listy1 doesn't just point to the same linked list that listy2
	// points to.
	assert(listy1->head != listy2->head);
	assert(listy1->head->next != listy2->head->next);
	assert(listy1->head->next->next != listy2->head->next->next);
	assert(listy1->head->next->next->next != listy2->head->next->next->next);
	assert(listy1->head->next->next->next->next != listy2->head->next->next->next->next);
	assert(listy1->head->next->next->next->next->next != listy2->head->next->next->next->next->next);

	printf("Hooray!\n");

	return 0;
}
