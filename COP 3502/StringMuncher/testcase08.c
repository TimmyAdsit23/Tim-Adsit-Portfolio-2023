// Sean Szumlanski
// COP 3502, Spring 2023

// ===========================
// StringMuncher: testcase08.c
// ===========================
// Tests basic omNomNom() and endoscopy() functionality.


#include <assert.h>
#include <stdio.h>
#include "StringMuncher.h"

int main(void)
{
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

	assert(endoscopy(munchy, 0) != str1);
	assert(endoscopy(munchy, 0) != NULL);

	assert(endoscopy(munchy, 1) != str2);
	assert(endoscopy(munchy, 1) != NULL);

	assert(endoscopy(munchy, 2) != str3);
	assert(endoscopy(munchy, 2) != NULL);

	printf("\nContents (via endoscopy):");
	printf("\n=========================\n");
	printf("%s\n", endoscopy(munchy, 0));
	printf("%s\n", endoscopy(munchy, 1));
	printf("%s\n", endoscopy(munchy, 2));
	printf("\n");

	banishStringMuncher(munchy);

	return 0;
}
