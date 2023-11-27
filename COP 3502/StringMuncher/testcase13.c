// Sean Szumlanski
// COP 3502, Spring 2023

// ===========================
// StringMuncher: testcase13.c
// ===========================
// Basic check to ensure banishStringMuncher() behaves properly with NULL
// pointers.


#include <assert.h>
#include <stdio.h>
#include "StringMuncher.h"

int main(void)
{
	banishStringMuncher(NULL);

	printf("Nothing to see here.\n");

	return 0;
}
