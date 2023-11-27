// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest41.c
// =========================
// Unit test for listyCmp(): Test the comparison of two NULL pointers.


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	assert(listyCmp(NULL, NULL) == 0);

	printf("Hooray!\n");

	return 0;
}
