// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest25.c
// =========================
// Unit test for reverseListyString(): Test the reversal of a NULL pointer. This
// essentially just checks whether there is a preventable segfault.


#include <assert.h>
#include <stdio.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	reverseListyString(NULL);

	printf("Hooray!\n");

	return 0;
}
