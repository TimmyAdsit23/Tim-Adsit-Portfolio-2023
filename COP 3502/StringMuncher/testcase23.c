// Sean Szumlanski
// COP 3502, Spring 2023

// ===========================
// StringMuncher: testcase23.c
// ===========================
// Tests the behavior of transmogrify() with various invalid inputs.


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

void printMunchyWithHeader(SM *munchy, char *header, int how_many)
{
	int i;
	int len = strlen(header);

	printf("%s\n", header);

	// Print bar.
	for (i = 0; i < len; i++)
		printf("=");
	printf("\n");

	for (i = 0; i < how_many; i++)
		printf("%s\n", endoscopy(munchy, i));

	printf("\n");
}

int main(void)
{
	int i = 0;

	char *name = "Moploch the Patient";
	int num_stomachs = 10;
	int num_snacks = 3;

	char *snacks[] = {"caterpillar",
	                  "cocoon",
	                  "butterfly"};

	SM *munchy = summonStringMuncher(name, num_stomachs);

	assert(munchy != NULL);

	for (i = 0; i < num_snacks; i++)
		omNomNom(munchy, snacks[i]);

	// The checkInternals() function is used to check whether everything
	// within munchy is as expected, without cluttering main() too much.

	checkInternals(munchy, name, num_stomachs, num_snacks, num_snacks, snacks);

	printf("\n");
	printMunchyWithHeader(munchy, "Before transformation:", 3);

	assert(transmogrify(munchy, -1, "rallipretac") == NULL);
	assert(transmogrify(munchy, 3, "rallipretac") == NULL);
	assert(transmogrify(munchy, 9, "rallipretac") == NULL);
	assert(transmogrify(munchy, 10, "rallipretac") == NULL);
	assert(transmogrify(munchy, 11, "rallipretac") == NULL);

	printMunchyWithHeader(munchy, "After transformation:", 3);

	printf("Digestive tract size: %d\n", getDigestiveTractSize(munchy));
	printf("Digestive tract capacity: %d\n\n", getDigestiveTractCapacity(munchy));

	assert(transmogrify(NULL, 2, "this string muncher does not exist") == NULL);

	banishStringMuncher(munchy);

	return 0;
}
