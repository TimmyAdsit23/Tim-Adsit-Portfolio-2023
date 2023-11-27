// Sean Szumlanski
// COP 3502, Spring 2023

// ===========================
// StringMuncher: testcase35.c
// ===========================
// Also checks that expandDigestiveTract() uses "stomach" (singular) in its
// output when we expand to just one stomach.


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
	char *name = "Loquid the Abstemious";
	int num_stomachs = 10;
	int num_stomachs_occupied;
	int num_snacks = 1;

	char *snacks[] = {"hypoplankton"};

	SM *munchy = summonStringMuncher(name, num_stomachs);

	assert(munchy != NULL);

	// The checkInternals() function is used to check whether everything
	// within munchy is as expected, without cluttering main() too much.

	checkInternals(munchy, name, num_stomachs, 0, 0, snacks);

	// This should bring the digestive tract down to capacity 0 (since there is
	// nothing in it yet), then expand it to capacity (2 * 0 + 1) = 1.
	contractDigestiveTract(munchy);
	omNomNom(munchy, snacks[0]);

	checkInternals(munchy, name, num_stomachs = 1, num_stomachs_occupied = 1, num_snacks, snacks);

	printf("\n");
	printStomachContents(munchy);

	printf("\n");
	printf("Digestive tract size: %d\n", getDigestiveTractSize(munchy));
	printf("Digestive tract capacity: %d\n\n", getDigestiveTractCapacity(munchy));

	banishStringMuncher(munchy);

	return 0;
}
