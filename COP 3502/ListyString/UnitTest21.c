// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest21.c
// =========================
// Unit test for listyCensor(): listy is NULL.


#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	ListyString *listy = NULL;
	char *badChars = "elder";

	printListyString(listy);
	listyCensor(listy, badChars);
	printListyString(listy);

	printf("Hooray!\n");

	return 0;
}
