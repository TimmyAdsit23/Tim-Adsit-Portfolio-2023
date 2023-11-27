// Sean Szumlanski
// COP 3502, Spring 2023

// ===========================
// StringMuncher: testcase03.c
// ===========================
// Basic check to ensure summonStringMuncher() is initializing everything
// correctly.


#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "StringMuncher.h"

int main(void)
{
	int i;

	char *name = "Thurburt";
	int num_stomachs = 14;

	SM *munchy = summonStringMuncher(name, num_stomachs);

	assert(munchy != NULL);
	assert(munchy->name != NULL);

	// Ensure the string muncher does not point to the string literal created
	// in this function. It needs its own dynamically allocated copy.
	assert(munchy->name != name);
	assert(strcmp(munchy->name, name) == 0);

	assert(munchy->num_stomachs == num_stomachs);
	assert(munchy->num_stomachs_occupied == 0);
	assert(munchy->stomachs != NULL);

	for (i = 0; i < num_stomachs; i++)
		assert(munchy->stomachs[i] == NULL);

	banishStringMuncher(munchy);

	return 0;
}
