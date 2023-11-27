// Sean Szumlanski
// COP 3502, Spring 2023

// ===========================
// StringMuncher: testcase12.c
// ===========================
// Tests the behavior of printStomachContents() with a NULL pointer.


#include <assert.h>
#include <stdio.h>
#include "StringMuncher.h"

int main(void)
{
	printStomachContents(NULL);

	return 0;
}
