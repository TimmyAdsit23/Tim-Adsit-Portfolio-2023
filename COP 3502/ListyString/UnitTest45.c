// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest45.c
// =========================
// Unit test for charCount(): Test with a NULL ListyString.


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	printf("'x' count: %d\n", charCount(NULL, 'x'));
	printf("'r' count: %d\n", charCount(NULL, 'r'));
	printf("' ' count: %d\n", charCount(NULL, ' '));
	printf("'\\0' count: %d\n", charCount(NULL, '\0'));

	return 0;
}
