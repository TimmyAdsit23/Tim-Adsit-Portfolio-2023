// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest23.c
// =========================
// Unit test for listyCensor(): operates on very long strings to help reveal
// whether the runtime is O(n + k) or O(nk).


#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "ListyString.h"

#define LONG_STRING_LENGTH 1000000

int unit_test(int argc, char **argv)
{
	int i;
	ListyString *listy;

	char extraLongString[LONG_STRING_LENGTH + 1];

	// Pointers to the first few original nodes in listy. The listyCensor()
	// function should modify the contents of existing nodes; it should not be
	// creating new nodes.
	ListyNode *originalNodes[4];

	// Generate very long string (a string with 1,000,000 'x' characters).
	for (i = 0; i < LONG_STRING_LENGTH; i++)
		extraLongString[i] = 'x';
	extraLongString[LONG_STRING_LENGTH] = '\0';

	listy = createListyString(extraLongString);
	originalNodes[0] = listy->head;
	originalNodes[1] = listy->head->next;
	originalNodes[2] = listy->head->next->next;
	originalNodes[3] = listy->head->next->next->next;

	printListyString(listy);
	listyCensor(listy, extraLongString);
	printListyString(listy);

	// Check that the first few original nodes are still intact.
	assert(originalNodes[0] == listy->head);
	assert(originalNodes[1] == listy->head->next);
	assert(originalNodes[2] == listy->head->next->next);
	assert(originalNodes[3] == listy->head->next->next->next);

	printf("Hooray!\n");

	return 0;
}
