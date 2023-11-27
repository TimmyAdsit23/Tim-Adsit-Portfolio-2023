#ifndef __STRING_MUNCHER_H
#define __STRING_MUNCHER_H

// =============================================================================
// WARNING ~ WARNING ~ WARNING ~ WARNING ~ WARNING ~ WARNING ~ WARNING ~ WARNING
// =============================================================================
//
// You should not copy the contents of this file into your StringMuncher.c file.
// Doing so may prevent your program from compiling and/or could lead to test
// case failure when we grade the assignment and/or catastrophic loss of credit.
// Instead, #include this header file from your StringMuncher.c file like so:
//
//    #include "StringMuncher.h"
//
// Please see the assignment PDF for more details, and please come to office
// hours if you have any questions about this setup or how to get test cases
// to compile and run.
//
// =============================================================================
// WARNING ~ WARNING ~ WARNING ~ WARNING ~ WARNING ~ WARNING ~ WARNING ~ WARNING
// =============================================================================


// Directives and Definitions

#define DEFAULT_DIGESTIVE_TRACT_CAPACITY 10

typedef struct StringMuncher
{
	// The name of this string muncher.
	char *name;

	// How many stomachs this string muncher currently has.
	int num_stomachs;

	// How many of the stomachs are occupied with (non-NULL) string pointers.
	int num_stomachs_occupied;

	// The string muncher's stomachs. Okay, so, it's just an array of string
	// pointers. Each cell represents a stomach, and each stomach/cell holds
	// a single string pointer.
	char **stomachs;
} StringMuncher;

typedef StringMuncher SM;


// Functional Prototypes

StringMuncher *summonStringMuncher(char *name, int num_stomachs);

StringMuncher *banishStringMuncher(StringMuncher *munchy);

StringMuncher *cloneStringMuncher(StringMuncher *munchy);

StringMuncher *expandDigestiveTract(StringMuncher *munchy, int num_stomachs);

StringMuncher *contractDigestiveTract(StringMuncher *munchy);

char *omNomNom(StringMuncher *munchy, char *snack);

char *endoscopy(StringMuncher *munchy, int which_stomach);

char *transmogrify(StringMuncher *munchy, int which_stomach, char *snack);

char *gobbleGulp(StringMuncher *munchy, int which_stomach, char *snack);

int digest(StringMuncher *munchy, int which_stomach);

int heave(StringMuncher *munchy);

int evacuate(StringMuncher *munchy);

int getDigestiveTractCapacity(StringMuncher *munchy);

int getDigestiveTractSize(StringMuncher *munchy);

void printStomachContents(StringMuncher *munchy);

double difficultyRating(void);

double hoursSpent(void);


#endif
