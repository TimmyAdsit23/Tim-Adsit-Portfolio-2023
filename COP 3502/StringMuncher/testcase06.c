// Sean Szumlanski
// COP 3502, Spring 2023

// ===========================
// StringMuncher: testcase06.c
// ===========================
// Tests basic omNomNom() functionality. Very similar to the previous test
// case, but this one passes read-only string literals to omNomNom() and
// checks that the strings inside the string muncher are actually new copies.


#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "StringMuncher.h"

int main(void)
{
	int i;

	char *name = "Thurburt";
	int num_stomachs = 10;

	char *str1 = "caterpillar";
	char *str2 = "beatific";
	char *str3 = "cocoon";

	SM *munchy = summonStringMuncher(name, num_stomachs);

	assert(munchy != NULL);

	omNomNom(munchy, str1);
	omNomNom(munchy, str2);
	omNomNom(munchy, str3);

	// Ensure the string muncher does not point to the string literal created
	// in this function. It needs its own dynamically allocated copy.
	assert(munchy->name != name);
	assert(munchy->name != NULL);
	assert(strcmp(munchy->name, name) == 0);

	assert(munchy->num_stomachs == num_stomachs);
	assert(munchy->num_stomachs_occupied == 3);
	assert(munchy->stomachs != NULL);

	for (i = 0; i < munchy->num_stomachs_occupied; i++)
		assert(munchy->stomachs[i] != NULL);

	for (i = 3; i < munchy->num_stomachs; i++)
		assert(munchy->stomachs[i] == NULL);

	// Checks that the strings in the stomach are new copies, not just pointers
	// to the string literals back here in main.
	assert(munchy->stomachs[0] != str1);
	assert(munchy->stomachs[1] != str2);
	assert(munchy->stomachs[2] != str3);

	assert(strcmp(munchy->stomachs[0], str1) == 0);
	assert(strcmp(munchy->stomachs[1], str2) == 0);
	assert(strcmp(munchy->stomachs[2], str3) == 0);

	banishStringMuncher(munchy);

	return 0;
}
