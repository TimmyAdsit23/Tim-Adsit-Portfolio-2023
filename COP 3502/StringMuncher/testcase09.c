// Sean Szumlanski
// COP 3502, Spring 2023

// ===========================
// StringMuncher: testcase09.c
// ===========================
// Tests endoscopy() out-of-bounds guards.


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

	// Check behavior on invalid indices.
	assert(endoscopy(munchy, -1) == NULL);
	assert(endoscopy(munchy, -5) == NULL);
	assert(endoscopy(munchy, 4) == NULL);
	assert(endoscopy(munchy, 10) == NULL);
	assert(endoscopy(munchy, 11) == NULL);
	assert(endoscopy(munchy, 12) == NULL);

	// Check behavior on invalid munchy. Ensure we don't crash here.
	assert(endoscopy(NULL, 0) == NULL);

	banishStringMuncher(munchy);

	return 0;
}
