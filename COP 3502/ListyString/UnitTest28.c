// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest28.c
// =========================
// Unit test for stringWeave(): str is shorter than listy.


#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	int i, length;
	char *result = "Hellooooo, dearie!";

	ListyNode *temp;
	ListyString *listy;
	ListyString *retval;

	// Pointers to original nodes in listy. These should not change.
	ListyNode *originalNodes[6];

	length = strlen(result);

	listy = createListyString("Hloooo, dearie!");
	originalNodes[0] = listy->head;
	originalNodes[1] = listy->head->next;
	originalNodes[2] = listy->head->next->next;
	originalNodes[3] = listy->head->next->next->next;
	originalNodes[4] = listy->head->next->next->next->next;
	originalNodes[5] = listy->head->next->next->next->next->next;
	retval = stringWeave(listy, "elo");

	// Print (mainly for debugging purposes).
	printListyString(listy);

	// Check contents of linked list.
	temp = listy->head;
	for (i = 0; i < length; i++)
	{
		assert(temp->data == result[i]);
		temp = temp->next;
	}

	// Check for proper NULL termination of linked list.
	assert(temp == NULL);

	// Check length variable.
	assert(listy->length == length);

	// Check return value of stringWeave().
	assert(retval == listy);

	// Check that the original nodes are still intact. Note that for nodes 0
	// through 3, we move forward 2 at a time because there are characters
	// interleaved between them. For nodes 4 and 5, we move forward 1 at a time
	// because there were no more characters in the string passed to
	// stringWeave() to be interleaved there.
	assert(originalNodes[0] == listy->head);
	assert(originalNodes[1] == listy->head->next->next);
	assert(originalNodes[2] == listy->head->next->next->next->next);
	assert(originalNodes[3] == listy->head->next->next->next->next->next->next);
	assert(originalNodes[4] == listy->head->next->next->next->next->next->next->next);
	assert(originalNodes[5] == listy->head->next->next->next->next->next->next->next->next);

	printf("Hooray!\n");

	return 0;
}
