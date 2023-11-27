// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest22.c
// =========================
// Unit test for listyCensor(): listy is empty string.


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
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
	ListyString *listy;
	char *badChars = "elder";

	// Create an empty string.
	listy = malloc(sizeof(ListyString));
	listy->head = NULL;
	listy->length = 0;

	printListyString(listy);
	listyCensor(listy, badChars);
	printListyString(listy);

	assert(listyEquals(listy, ""));

	printf("Hooray!\n");

	return 0;
}
