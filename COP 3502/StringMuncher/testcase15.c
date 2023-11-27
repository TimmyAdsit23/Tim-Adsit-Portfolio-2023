// Sean Szumlanski
// COP 3502, Spring 2023

// ===========================
// StringMuncher: testcase15.c
// ===========================
// Tests automatic expansion functionality. This test case should cause omNomNom()
// to call expandDigestiveTract().


#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "StringMuncher.h"


void checkInternals(SM *munchy, char *name, int expected_num_stomachs,
                     int expected_stomachs_occupied, int num_snacks, char *snacks[])
{
	int i;

	// Ensure the string muncher does not point to the string literal created
	// in this function. It needs its own dynamically allocated copy.
	assert(munchy->name != name);
	assert(munchy->name != NULL);
	assert(strcmp(munchy->name, name) == 0);

	assert(munchy->num_stomachs == expected_num_stomachs);
	assert(munchy->num_stomachs_occupied == expected_stomachs_occupied);
	assert(munchy->stomachs != NULL);

	for (i = 0; i < expected_stomachs_occupied; i++)
	{
		assert(munchy->stomachs[i] != NULL);
		assert(strcmp(munchy->stomachs[i], snacks[i]) == 0);

		// Ensure the stomach doesn't just refer to the string literal from the
		// snacks array. It needs to have its own dynamically allocated copy.
		assert(munchy->stomachs[i] != snacks[i]);
	}

	for (i = expected_stomachs_occupied; i < expected_num_stomachs; i++)
	{
		assert(munchy->stomachs[i] == NULL);
	}
}

int main(void)
{
	int i = 0;

	char *name = "Womblotian";
	int num_stomachs = 10;
	int num_snacks = 12;

	char *snacks[] = {"munch", "munch", "munch!",
	                  "monch", "monch", "monch!",
	                  "muncha", "muncha", "muncha!",
	                  "CRONCH", "CRONCH", "CRONCH!"};

	SM *munchy = summonStringMuncher(name, num_stomachs);

	assert(munchy != NULL);

	omNomNom(munchy, snacks[i++]);
	omNomNom(munchy, snacks[i++]);
	omNomNom(munchy, snacks[i++]);

	omNomNom(munchy, snacks[i++]);
	omNomNom(munchy, snacks[i++]);
	omNomNom(munchy, snacks[i++]);

	omNomNom(munchy, snacks[i++]);
	omNomNom(munchy, snacks[i++]);
	omNomNom(munchy, snacks[i++]);

	// The checkInternals() function is used to check whether everything
	// within munchy is as expected, without cluttering main() too much.

	omNomNom(munchy, snacks[i++]);
	checkInternals(munchy, name, num_stomachs, i, num_snacks, snacks);

	// This next one is the one that should trigger the expansion.
	omNomNom(munchy, snacks[i++]);
	checkInternals(munchy, name, num_stomachs * 2 + 1, i, num_snacks, snacks);

	omNomNom(munchy, snacks[i++]);
	checkInternals(munchy, name, num_stomachs * 2 + 1, i, num_snacks, snacks);

	printf("\n");
	printf("Stomach contents at end of program:\n");
	printf("===================================\n");
	for (i = 0; i < munchy->num_stomachs_occupied; i++)
		printf("%s\n", endoscopy(munchy, i));
	printf("\n");

	printf("Digestive tract size: %d\n", getDigestiveTractSize(munchy));
	printf("Digestive tract capacity: %d\n\n", getDigestiveTractCapacity(munchy));

	banishStringMuncher(munchy);

	return 0;
}
