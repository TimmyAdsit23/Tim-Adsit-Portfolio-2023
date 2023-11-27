// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest19.c
// =========================
// Unit test for listyCensor(): Checks the example given in the PDF.


#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	ListyString *listy = createListyString("dwindle");
	char *badChars = "elder!@#$%^&*()_+";

	// Pointers to the first few original nodes in listy. The listyCensor()
	// function should modify the contents of existing nodes; it should not be
	// creating new nodes.
	ListyNode *originalNodes[7];

	originalNodes[0] = listy->head;
	originalNodes[1] = listy->head->next;
	originalNodes[2] = listy->head->next->next;
	originalNodes[3] = listy->head->next->next->next;
	originalNodes[4] = listy->head->next->next->next->next;
	originalNodes[5] = listy->head->next->next->next->next->next;
	originalNodes[6] = listy->head->next->next->next->next->next->next;

	printListyString(listy);
	listyCensor(listy, badChars);
	printListyString(listy);

	// Check that the original nodes are still intact.
	assert(originalNodes[0] == listy->head);
	assert(originalNodes[1] == listy->head->next);
	assert(originalNodes[2] == listy->head->next->next);
	assert(originalNodes[3] == listy->head->next->next->next);
	assert(originalNodes[4] == listy->head->next->next->next->next);
	assert(originalNodes[5] == listy->head->next->next->next->next->next);
	assert(originalNodes[6] == listy->head->next->next->next->next->next->next);

	printf("Hooray!\n");

	return 0;
}
