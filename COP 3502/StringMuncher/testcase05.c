// Sean Szumlanski
// COP 3502, Spring 2023

// ===========================
// StringMuncher: testcase05.c
// ===========================
// Tests basic omNomNom() functionality.


#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "StringMuncher.h"

int main(void)
{
	int i;

	char *name = "Thurburt";
	int num_stomachs = 10;

	SM *munchy = summonStringMuncher(name, num_stomachs);

	assert(munchy != NULL);

	omNomNom(munchy, "caterpillar");
	omNomNom(munchy, "beatific");
	omNomNom(munchy, "cocoon");

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

	assert(strcmp(munchy->stomachs[0], "caterpillar") == 0);
	assert(strcmp(munchy->stomachs[1], "beatific") == 0);
	assert(strcmp(munchy->stomachs[2], "cocoon") == 0);

	banishStringMuncher(munchy);

	return 0;
}
