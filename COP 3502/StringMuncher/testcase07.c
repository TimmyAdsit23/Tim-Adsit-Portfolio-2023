// Sean Szumlanski
// COP 3502, Spring 2023

// ===========================
// StringMuncher: testcase07.c
// ===========================
// Basic check to ensure summonStringMuncher() behaves properly with NULL
// pointers.


#include <assert.h>
#include <stdio.h>
#include "StringMuncher.h"

int main(void)
{
	SM *munchy;

	munchy = summonStringMuncher(NULL, 10);
	assert(munchy == NULL);

	munchy = summonStringMuncher("", 10);
	assert(munchy == NULL);

	printf("Nothing to see here.\n");

	return 0;
}
