// Sean Szumlanski
// COP 3502, Spring 2023

// =========================
// ListyString: UnitTest52.c
// =========================
// Quick check to ensure that processInputFile() returns 1 when it fails to
// find the specified input file.


#include <assert.h>
#include <stdio.h>
#include "ListyString.h"

int unit_test(int argc, char **argv)
{
	assert(processInputFile("__NO_FILE_BY_THIS_NAME_SHOULD_EXIST__") == 1);
	printf("Hooray!\n");

	return 0;
}
