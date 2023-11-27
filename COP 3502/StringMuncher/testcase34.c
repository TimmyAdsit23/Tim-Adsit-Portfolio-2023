// Sean Szumlanski
// COP 3502, Spring 2023

// ===========================
// StringMuncher: testcase34.c
// ===========================
// Further tests of digest() functionality.


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

	char *name = "Loquid the Abstemious";
	int num_stomachs = 10;
	int num_snacks = 4;

	char *snacks[] = {"hypoplankton", "algae", "seaweed", "kelp"};

	SM *munchy = summonStringMuncher(name, num_stomachs);

	assert(munchy != NULL);

	for (i = 0; i < num_snacks; i++)
		omNomNom(munchy, snacks[i]);

	// The checkInternals() function is used to check whether everything
	// within munchy is as expected, without cluttering main() too much.

	checkInternals(munchy, name, num_stomachs, num_snacks, num_snacks, snacks);

	printf("\n");
	printf("Before digestion:\n");
	printf("=================\n");
	printStomachContents(munchy);

	// NOTE: After shifting strings down to account for digestion, we should
	//       have a NULL pointer in whichever stomach is newly unoccupied.

	digest(munchy, 1);
	assert(munchy->stomachs[3] == NULL);

	printf("\n");
	printf("After first digestion:\n");
	printf("======================\n");
	printStomachContents(munchy);

	digest(munchy, 2);
	assert(munchy->stomachs[2] == NULL);
	assert(munchy->stomachs[3] == NULL);

	printf("\n");
	printf("After second digestion:\n");
	printf("=======================\n");
	printStomachContents(munchy);

	digest(munchy, 0);
	assert(munchy->stomachs[1] == NULL);
	assert(munchy->stomachs[2] == NULL);
	assert(munchy->stomachs[3] == NULL);

	printf("\n");
	printf("After third digestion:\n");
	printf("======================\n");
	printStomachContents(munchy);

	printf("\n");
	printf("Digestive tract size: %d\n", getDigestiveTractSize(munchy));
	printf("Digestive tract capacity: %d\n\n", getDigestiveTractCapacity(munchy));

	banishStringMuncher(munchy);

	return 0;
}
