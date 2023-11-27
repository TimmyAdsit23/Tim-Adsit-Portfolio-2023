#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StringMuncher.h"

StringMuncher freeStomachs(char** stomachs, int numOldStomachs);
StringMuncher *summonStringMuncher(char *name, int num_stomachs);
StringMuncher *banishStringMuncher(StringMuncher *munchy);
StringMuncher *expandDigestiveTract(StringMuncher *munchy, int num_stomachs);
StringMuncher *contractDigestiveTract(StringMuncher *munchy);
char *omNomNom(StringMuncher *munchy, char *snack);
char *endoscopy(StringMuncher *munchy, int which_stomach);
char *transmogrify(StringMuncher *munchy, int which_stomach, char *snack);
char *gobbleGulp(StringMuncher *munchy, int which_stomach, char *snack);
void SOMETHINGSWRONG(int a);
int digest(StringMuncher *munchy, int which_stomach);
int heave(StringMuncher *munchy);
int evacuate(StringMuncher *munchy);
int getDigestiveTractCapacity(StringMuncher *munchy);
int getDigestiveTractSize(StringMuncher *munchy);
void printStomachContents(StringMuncher *munchy);
double difficultyRating(void);
double hoursSpent(void);

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








StringMuncher freeStomachs(char** stomachs, int numOldStomachs)
{
   int x;
   for(x = 0; x < numOldStomachs; x++)
   {
      free(stomachs[x]);
   }
   free(stomachs);
}

StringMuncher *summonStringMuncher(char *name, int num_stomachs)
{
   int sizeName;
   int actualNumStomachs;
   int doesntWork = 0;
   char *stomach;

   if(name == NULL)
   {
      return NULL;
   }
   if(strcmp("", name) == 0)
   {
      return NULL;
   }

   sizeName = strlen(name);
      
   


   if(num_stomachs < DEFAULT_DIGESTIVE_TRACT_CAPACITY)
      actualNumStomachs = DEFAULT_DIGESTIVE_TRACT_CAPACITY;
   else
      actualNumStomachs = num_stomachs;

   StringMuncher *new = malloc(sizeof(StringMuncher));
   
   new->name = malloc(sizeof(char) * (sizeName+1));
   strcpy(new->name, name);

   if(new->name == NULL)
      doesntWork == 1;

   // makes stomachs and inits to NULL
   new->stomachs = malloc(sizeof(char*) * (actualNumStomachs));

   if(new->stomachs == NULL)
      doesntWork = 1;

   if(doesntWork)
   {
      free(new->stomachs);
      free(new->name);
      return NULL;
   }

   // initializes the char arrays in the stomachs to NULL
   for(int i = 0; i < actualNumStomachs; i++)
   {
      new->stomachs[i] = NULL;
   }

   new->num_stomachs = actualNumStomachs;
   new->num_stomachs_occupied = 0;


   if(actualNumStomachs == 1)
      stomach = "stomach";
   else
      stomach = "stomachs";

   printf("-> %s, a string muncher with %d %s, ", name, actualNumStomachs, stomach);
   printf("has emerged from the void!\n");

   return new;
}

StringMuncher *banishStringMuncher(StringMuncher *munchy)
{
   if(munchy == NULL)
      return NULL;

   printf("-> %s has returned to the void.\n", munchy->name);

   free(munchy->name);

   for(int i = 0; i < munchy->num_stomachs_occupied; i++)
         free(munchy->stomachs[i]);

   free(munchy->stomachs);
   return NULL;
}

StringMuncher *expandDigestiveTract(StringMuncher *munchy, int num_stomachs)
{
   // one stomach is one string in the string array
   char **newStomachs;
   int numOldStomachs, i, j, x, doesntWork = 0;
   int *sizeOfStrings;
   int numOccupiedStomachs;
   char* stomach;
   
   if(munchy == NULL)
      return NULL;

   if(num_stomachs <= munchy->num_stomachs)
      return NULL;
      

   numOldStomachs = munchy->num_stomachs_occupied;
   newStomachs = malloc(sizeof(char*) * (num_stomachs));
   sizeOfStrings = malloc(sizeof(int) * numOldStomachs);

   if(newStomachs == NULL || sizeOfStrings == NULL)
      doesntWork == 1;



   // goes through every old stomach to get the length of the string
   for(i = 0; i < numOldStomachs; i++)
   {
      // gets the size of all the strings in the munchy string stomachs
      sizeOfStrings[i] = strlen(munchy->stomachs[i]);
      if(sizeOfStrings[i] > 0)
         numOccupiedStomachs++;
   }

   for(j = 0; j < numOldStomachs; j++)
   {
      newStomachs[j] = malloc(sizeof(char) * (sizeOfStrings[j] + 1));
      strcpy(newStomachs[j], munchy->stomachs[j]);
      if(newStomachs[j] == NULL)
         doesntWork = 1;
   }
   for(j; j < num_stomachs; j++)
   {
      // initialize the rest of the newStomachs to NULL
      newStomachs[j] = NULL;
   }

   // check if the memory was corretly allocated
   if(doesntWork)
   {
      for(j = 0; j < num_stomachs; j++)
      {
         free(newStomachs[j]);
      }
      free(newStomachs);
      free(sizeOfStrings);
      return munchy;
   }

   // now we free the old stomachs
   freeStomachs(munchy->stomachs, numOldStomachs);

   // point the stomachs in munchy to the newStomachs array
   munchy->stomachs = newStomachs;
   munchy->num_stomachs = num_stomachs;

   if(num_stomachs > 1)
      stomach = "stomachs";
   else
      stomach = "stomach";
   
   // this is if the stomachs were not expanded
   if(munchy->num_stomachs == numOldStomachs)
      return munchy;

   printf("-> %s's digestive tract has expanded to consist of", munchy->name);
   printf(" %d %s!\n", munchy->num_stomachs, stomach);

   free(sizeOfStrings);
   return munchy;
}

StringMuncher *contractDigestiveTract(StringMuncher *munchy)
{
   int i, doesntWork = 0, sizeOfString, count;
   char** newStomachArray;
   char* stomachs = "stomachs";

   if(munchy == NULL)
      return munchy;
   if(munchy->num_stomachs <= munchy->num_stomachs_occupied)
      return NULL;

   newStomachArray = malloc(sizeof(char*) * (munchy->num_stomachs_occupied));

   if(newStomachArray == NULL)
      doesntWork = 1;


   // i goes through the munchy->num_stomachs
   // counter goes through every elegable string in the stomach
   for(i = 0; i < munchy->num_stomachs_occupied; i++)
   {
         // malloc new string in newStomachArray
         newStomachArray[i] = munchy->stomachs[i];
   }


   if(doesntWork)
   {
      // here count represents how many mallocs were successfully allocated
      freeStomachs(newStomachArray, count);
      return munchy;
   }

   // free old stomach
   free(munchy->stomachs);

   munchy->num_stomachs = munchy->num_stomachs_occupied;
   munchy->stomachs = newStomachArray;

   if(munchy->num_stomachs == 1)
      stomachs = "stomach";
   printf("-> %s's digestive tract has contracted to consist of only ", munchy->name);
   printf("%d %s!\n", munchy->num_stomachs, stomachs);

   return munchy;
}

char *omNomNom(StringMuncher *munchy, char *snack)
{
   int i;

   if(munchy == NULL)
   {
      printf("%s is NULL\n", munchy->name);
      return NULL;
   }
   if(snack == NULL)
   {
      printf("%s is NULL\n", snack);
      return NULL;
   }

   // stomach 0 is the bottom, puts newest string at lowest possible stomach
   if(munchy->num_stomachs_occupied == munchy->num_stomachs)
      expandDigestiveTract(munchy, munchy->num_stomachs * 2 + 1);

   // printf("going through loop now:\n");
   // loops through the munchy stomach until a free space.
   for(i = 0; i < munchy->num_stomachs; i++)
   {
      // printf("currently at i = %d\n", i);
      // printf("munchy->stomachs[%d] is: %s\n", i, munchy->stomachs[i]);
      if(munchy->stomachs[i] == NULL)
      {
         // printf("The stomach at %d is free and the string ->%s<- was placed there\n", i, snack);
         munchy->stomachs[i] = malloc(sizeof(char) * (strlen(snack) + 1));
         // strcpy(munchy->stomachs[i], snack);

         strcpy(munchy->stomachs[i], snack);
         munchy->num_stomachs_occupied++;
         

         if(strcmp(munchy->stomachs[i], snack) != 0)
         {
            // DEBUG ONLY
            SOMETHINGSWRONG(__LINE__);
         }
         // printf("munchy->stomachs[%d] is %s\n", i, snack);
         // printf("munchy->num_stomachs_occupied: %d\n", munchy->num_stomachs_occupied);

         break;
      }
   }

   return munchy->stomachs[i];
}

char *endoscopy(StringMuncher *munchy, int which_stomach)
{
   if(munchy == NULL)
      return NULL;
   if(which_stomach > munchy->num_stomachs-1)
      return NULL;
   if(which_stomach < 0)
      return NULL;
   
   return munchy->stomachs[which_stomach];
}

char *transmogrify(StringMuncher *munchy, int which_stomach, char *snack)
{
   if(munchy == NULL)
      return NULL;
   if(endoscopy(munchy, which_stomach) == NULL)
      return NULL;
   if(snack == NULL)
      return NULL;
   
   char* toBeMogrified = endoscopy(munchy, which_stomach);

   free(munchy->stomachs[which_stomach]);
   munchy->stomachs[which_stomach] = malloc(sizeof(char*) * (strlen(toBeMogrified) + 1));
   if(munchy->stomachs == NULL)
      return NULL;
   
   strcpy(munchy->stomachs[which_stomach], snack);

   return munchy->stomachs[which_stomach];
}

char *gobbleGulp(StringMuncher *munchy, int which_stomach, char *snack)
{
   int i, doesntWork = 0;
   if(munchy == NULL)
      return NULL;
   if(which_stomach < 0)
      return NULL;
   if(snack == NULL)
      return NULL;

   if(munchy->num_stomachs == munchy->num_stomachs_occupied)
      expandDigestiveTract(munchy, munchy->num_stomachs * 2 + 1);

   char** newStomachArray = malloc(sizeof(char*) * munchy->num_stomachs);
   if(newStomachArray == NULL)
      {
         return NULL;
      }

   // fills stomach with old strings that aren't moved up 1
   for(i = 0; i < which_stomach; i++)
   {
      if(munchy->stomachs[i] == NULL)
         break;
      newStomachArray[i] = munchy->stomachs[i];
   }


   // put new snack at which_stomach
   newStomachArray[i] = malloc(sizeof(char) * (strlen(snack) + 1));
   strcpy(newStomachArray[i], snack);
   i++;

   // fills stomach with old strings that are moved up 1
   // index of the old stomachs needs to be i-1
   // because of the old stomachs not being changed
   for(i; i < munchy->num_stomachs; i++)
   {
      newStomachArray[i] = munchy->stomachs[i-1];
   }

   free(munchy->stomachs);
   munchy->num_stomachs_occupied++;
   munchy->stomachs = newStomachArray;

   return munchy->stomachs[which_stomach];
}

void SOMETHINGSWRONG(int a)
{
   printf("===============================");
   printf("SOMETHING IS WRONG AT LINE %d\n", a);
   printf("===============================");
}

int digest(StringMuncher *munchy, int which_stomach)
{
   int i;
   if(munchy == NULL)
      return 0;
   if(munchy->num_stomachs_occupied == 1)
   {
      free(munchy->stomachs[which_stomach]);
      munchy->num_stomachs_occupied--;
      munchy->stomachs[which_stomach] = NULL;
      return 1;
   }

   free(munchy->stomachs[which_stomach]);

   for(i = which_stomach; i < munchy->num_stomachs_occupied-1; i++)
   {
      munchy->stomachs[i] = munchy->stomachs[i+1];
   }

   munchy->num_stomachs_occupied--;
   munchy->stomachs[i] = NULL;

   return 1;
}

int heave(StringMuncher *munchy)
{
   if(munchy == NULL)
      return 0;
   if(munchy->num_stomachs_occupied == 0)
      return 0;

   free(munchy->stomachs[munchy->num_stomachs_occupied-1]);
   munchy->stomachs[munchy->num_stomachs_occupied-1] = NULL;
   munchy->num_stomachs_occupied--;
   return 1;
}

int evacuate(StringMuncher *munchy)
{
   if(munchy == NULL || munchy->num_stomachs_occupied == 0)
      return 0;

   if(!digest(munchy, 0))
      return 0;
   
   return 1;
}

int getDigestiveTractCapacity(StringMuncher *munchy)
{
   if(munchy == NULL)
      return -1;

   return munchy->num_stomachs;
}

int getDigestiveTractSize(StringMuncher *munchy)
{
   if(munchy == NULL)
      return -1;

   return munchy->num_stomachs_occupied;
}

void printStomachContents(StringMuncher *munchy)
{
   int i;

   if(munchy == NULL)
   {
      printf("(?\?\?)\n");
      return;
   }
   if(munchy->num_stomachs_occupied == 0)
   {
      printf("(%s's digestive tract is empty.)\n", munchy->name);
      return;
   }

   for(int i = 0; i < munchy->num_stomachs_occupied; i++)
   {
      printf("i: %d\n", i);
      printf("munchy->stomachs[i]: %s\n", munchy->stomachs[i]);
   }
      

}

double difficultyRating(void)
{
   return 3.5;
}

double hoursSpent(void)
{
   return 7;
}
