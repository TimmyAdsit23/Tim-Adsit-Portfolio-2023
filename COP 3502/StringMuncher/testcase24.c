// Sean Szumlanski
// COP 3502, Spring 2023

// ===========================
// StringMuncher: testcase24.c
// ===========================
// Tests gobbleGulp() functionality.


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

	char *name = "Moncht";
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
	printMunchyWithHeader(munchy, "Before gulp:", munchy->num_stomachs_occupied);

	gobbleGulp(munchy, 1, "rallipretac");
	printMunchyWithHeader(munchy, "After first gulp:",  munchy->num_stomachs_occupied);

	gobbleGulp(munchy, 3, "noococ");
	printMunchyWithHeader(munchy, "After second gulp:",  munchy->num_stomachs_occupied);

	gobbleGulp(munchy, 5, "ylfrettub");
	printMunchyWithHeader(munchy, "After third gulp:",  munchy->num_stomachs_occupied);

	gobbleGulp(munchy, 9, "top of digestive tract");
	printMunchyWithHeader(munchy, "After fourth gulp:",  munchy->num_stomachs_occupied);

	gobbleGulp(munchy, 0, "bottom of digestive tract");
	printMunchyWithHeader(munchy, "After fifth gulp:",  munchy->num_stomachs_occupied);

	printf("Digestive tract size: %d\n", getDigestiveTractSize(munchy));
	printf("Digestive tract capacity: %d\n\n", getDigestiveTractCapacity(munchy));

	banishStringMuncher(munchy);

	return 0;
}
