// Sean Szumlanski
// COP 3502, Spring 2023

// ==========================
// StringMuncher: CloneTest.c
// ==========================
// Tests the functionality of cloneStringMuncher(). This is a bonus test case.


#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "StringMuncher.h"

// Checks that the internals of the string munchers in this test cases are all
// set up as expected.
void munchyCheck(SM *munchy, char *name)
{
	int i;
	int expected_num_stomachs = 99;
	int expected_num_stomachs_occupied = 3;

	// Ensure the string muncher does not point to the string literal created
	// in this function. It needs its own dynamically allocated copy.
	assert(munchy->name != name);
	assert(munchy->name != NULL);
	assert(strcmp(munchy->name, name) == 0);

	assert(munchy->num_stomachs == expected_num_stomachs);
	assert(munchy->num_stomachs_occupied == expected_num_stomachs_occupied);
	assert(munchy->stomachs != NULL);

	for (i = 0; i < munchy->num_stomachs_occupied; i++)
		assert(munchy->stomachs[i] != NULL);

	for (i = 3; i < munchy->num_stomachs; i++)
		assert(munchy->stomachs[i] == NULL);

	assert(strcmp(munchy->stomachs[0], "caterpillar") == 0);
	assert(strcmp(munchy->stomachs[1], "beatific") == 0);
	assert(strcmp(munchy->stomachs[2], "cocoon") == 0);
}

int main(void)
{
	char *name = "Malthywix";
	int num_stomachs = 99;

	SM *munchy = summonStringMuncher(name, num_stomachs);
	SM *clone;

	assert(munchy != NULL);

	omNomNom(munchy, "caterpillar");
	omNomNom(munchy, "beatific");
	omNomNom(munchy, "cocoon");

	clone = cloneStringMuncher(munchy);

	// Ensure internals of both munchy and clone are good.
	printf("\n");
	munchyCheck(munchy, name);
	printf("Original internals look good!\n");

	munchyCheck(clone, name);
	printf("Clone internals look good!\n");
	printf("\n");

	// Ensure clone has its own copies of all strings.
	assert(munchy->name != clone->name);
	assert(munchy->stomachs[0] != clone->stomachs[0]);
	assert(munchy->stomachs[1] != clone->stomachs[1]);
	assert(munchy->stomachs[2] != clone->stomachs[2]);

	banishStringMuncher(munchy);
	banishStringMuncher(clone);

	return 0;
}
