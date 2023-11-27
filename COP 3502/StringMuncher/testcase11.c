// Sean Szumlanski
// COP 3502, Spring 2023

// ===========================
// StringMuncher: testcase11.c
// ===========================
// Tests the behavior of printStomachContents() with an empty digestive tract.


#include <assert.h>
#include <stdio.h>
#include "StringMuncher.h"

int main(void)
{
	char *name = "Loquid the Abstemious";
	int num_stomachs = 10;

	SM *munchy = summonStringMuncher(name, num_stomachs);

	assert(munchy != NULL);
	assert(munchy->stomachs != NULL);
	assert(munchy->num_stomachs == num_stomachs);
	assert(munchy->num_stomachs_occupied == 0);

	printf("\n");
	printStomachContents(munchy);
	printf("\n");

	banishStringMuncher(munchy);

	return 0;
}
