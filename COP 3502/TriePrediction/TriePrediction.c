// Tim Adsit
// COP 3502, Spring 2023
// ti047614

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TriePrediction.h"
#define MAX_WORD_LENGTH 1023

/*

typedef struct TrieNode
{
	// number of times this string occurs in the corpus
	int count;
	// 26 TrieNode pointers, one for each letter of the alphabet
	struct TrieNode *children[26];
	// the co-occurrence subtrie for this string
	struct TrieNode *subtrie;
} TrieNode;

*/

char *removePunctuation(char *string);
int hasKids(TrieNode *root);
int getLargestCount(TrieNode *root);
int prefixCountHelper(TrieNode *root);
int newNodeCountHelper(TrieNode *root, char *str, int length);
TrieNode *buildSubTrie(TrieNode *root, char *str);
TrieNode *insertToSubTrie(TrieNode *root, char *str);

// Helper function called by printTrie(). (Credit: Dr. S.)
void printTrieHelper(TrieNode *root, char *buffer, int k)
{
	int i;

	if (root == NULL)
		return;

	if (root->count > 0)
		printf("%s (%d)\n", buffer, root->count);

	buffer[k + 1] = '\0';

	for (i = 0; i < 26; i++)
	{
		buffer[k] = 'a' + i;

		printTrieHelper(root->children[i], buffer, k + 1);
	}

	buffer[k] = '\0';
}

// If printing a subtrie, the second parameter should be 1; otherwise, if
// printing the main trie, the second parameter should be 0. (Credit: Dr. S.)
void printTrie(TrieNode *root, int useSubtrieFormatting)
{
	char buffer[1026];

	if (useSubtrieFormatting)
	{
		strcpy(buffer, "- ");
		printTrieHelper(root, buffer, 2);
	}
	else
	{
		strcpy(buffer, "");
		printTrieHelper(root, buffer, 0);
	}
}

int processinputFileName(TrieNode *root, char *filename)
{
	return 0;
}

TrieNode *destroyTrie(TrieNode *root)
{
	int i;

	if(root == NULL)
		return NULL;

	for(i = 0; i < 26; i++)
		destroyTrie(root->children[i]);

	free(root);

	return NULL;
}

TrieNode *getNode(TrieNode *root, char *str)
{
	if(root == NULL)
	{
		return NULL;
	}
	if(strcmp(str, "") == 0)
	{
		return NULL;
	}
	if(!isalpha(str[1]) && root->count >= 1)
	{
		return root;
	}
	
	return getNode(root->children[str[0] - 'a'], str + 1);
}

void getMostFrequentWord(TrieNode *root, char *str)
{
	int i;
	int temp;

	if(root == NULL)
		return;

	int largest = getLargestCount(root);

	for(i = 0; i < 26; i++)
	{
		temp = getLargestCount(root->children[i]);
		if(temp == largest)
		{
			str[0] = i + 'a';
			getMostFrequentWord(root->children[i], str + 1);
			break;
		}
	}
}

int containsWord(TrieNode *root, char *str)
{
	if(root == NULL)
		return 0;
	if(strcmp(str, "") == 0)
		return 1;
	if(str[1] == '\0' && root->count == 1)
		return 1;
	
	return containsWord(root->children[str[0] - 'a'], str + 1);
}

int prefixCount(TrieNode *root, char *str)
{
	TrieNode *endOfPrefix;
	int count;

	if(root == NULL)
		return 0;
	

	endOfPrefix = getNode(root, str);

	return prefixCountHelper(endOfPrefix);
}

int prefixCountHelper(TrieNode *root)
{
	int count, i;

	if(root == NULL)
		return 0;

	count = 0;
	count = root->count;

	for(i = 0; i < 26; i++)
		count += prefixCountHelper(root->children[i]);

	return count;
}

int newNodeCount(TrieNode *root, char *str)
{
	char *noPunct;
	int noPunctLength;

	noPunct = removePunctuation(str);
	noPunctLength = strlen(noPunct);

	noPunct[noPunctLength-1] = '\0';

	return newNodeCountHelper(root, noPunct, noPunctLength-1);
}

int newNodeCountHelper(TrieNode *root, char *str, int length)
{
	char *strMinusOne;
	int i, len;

	if(str == NULL)
		return 0;
	
	if(root == NULL)
		return 0;

	

	// strMinusOne = malloc(sizeof(char)* length - 1);
	// if it returns null, then the full string doesn't exist in the trie. remove a letter off the
	// end and check if it exists in the trie. repeat until true

	if(containsWord(root, str) == 0)
	{
		str[length-1] = '\0';
		return 1 + newNodeCountHelper(root, str, length - 1);
	}

	return 0;
}

double difficultyRating(void)
{
	return 4.0;
}

double hoursSpent(void)
{
	return 16; //started at 3:03 PM on 4/21
			  // ended 4:30 pm
				// started 8 PM
				
}


// ==========================================================================================
// HELPER STUFF
// ==========================================================================================


// Code courtesy of: Sean Szumlansky
// Code from COP3502H_CMB-23Spring 00336 > Pages > Tries (Part 2 of 2) > tries.c

// Basic TrieNode creation function.
TrieNode *createNode(void)
{
	return calloc(1, sizeof(TrieNode));
}

// Insert a string into a trie. This function returns the root of the trie.
TrieNode *insert(TrieNode *root, char *str)
{
	int i, index, len = strlen(str);
	TrieNode *wizard;

	if (root == NULL)
		root = createNode();

	// As I mentioned in class, the wizard starts at the root node and spells
	// out the string being inserted as he/she jumps from node to node. (The
	// wizard is acting as a temp pointer.)
	wizard = root;

	for (i = 0; i < len; i++)
	{
		// This is kind of gross. There are probably cleaner ways of dealing with
		// this than simply printing an error and returning NULL.
		if (!isalpha(str[i]))
		{
			fprintf(stderr, "Error: \"%s\" contains non-alpha characters and will not be inserted.\n", str);
			return NULL;
		}

		index = tolower(str[i]) - 'a';

		// Before the wizard can move forward to the next node, (s)he needs to
		// make sure that node actually exists. If not, create it!
		if (wizard->children[index] == NULL)
			wizard->children[index] = createNode();

		// Now the wizard is able to jump forward.
		wizard = wizard->children[index];
	}

	// When we break out of the for-loop, the wizard should be at the terminal
	// node that represents the string we're trying to insert.
	wizard->count++;
	return root;
}

// Open an input file and build a trie from its contents. Assumes the input file
// contains no punctuation.
TrieNode *buildTrie(char *filename)
{
	TrieNode *root = NULL; 
	TrieNode *prevWord;
	char buffer[MAX_WORD_LENGTH + 1];
	char *betterBuffer;
	int started = 0;

	FILE *ifp;

	if ((ifp = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Failed to open \"%s\" in buildTrie().\n", filename);
		return NULL;
	}

	// Insert strings one-by-one into the trie.
	while (fscanf(ifp, "%s", buffer) != EOF)
	{
		betterBuffer = removePunctuation(buffer);
		// build the subtrie
		if(started)
		{
			buildSubTrie(prevWord, buffer);
		}
		root = insert(root, betterBuffer);
		prevWord = getNode(root, betterBuffer);
		started = 1;
	}

	fclose(ifp);
	return root;
}

// ends borrowed code

// root is the root of the node that is getting a subtrie
TrieNode *buildSubTrie(TrieNode *root, char *str)
{
	root = insertToSubTrie(root, str);
	return root;
}

TrieNode *insertToSubTrie(TrieNode *root, char *str)
{
	int i, index, len = strlen(str);
	TrieNode *wizard;

	if (root == NULL)
		root->subtrie = createNode();

	// As I mentioned in class, the wizard starts at the root node and spells
	// out the string being inserted as he/she jumps from node to node. (The
	// wizard is acting as a temp pointer.)
	wizard = root->subtrie;

	for (i = 0; i < len; i++)
	{
		// This is kind of gross. There are probably cleaner ways of dealing with
		// this than simply printing an error and returning NULL.
		if (!isalpha(str[i]))
		{
			fprintf(stderr, "Error: \"%s\" contains non-alpha characters and will not be inserted.\n", str);
			return NULL;
		}

		index = tolower(str[i]) - 'a';

		// Before the wizard can move forward to the next node, (s)he needs to
		// make sure that node actually exists. If not, create it!
		if (wizard->children[index] == NULL)
			wizard->children[index] = createNode();

		// Now the wizard is able to jump forward.
		wizard = wizard->children[index];
	}

	// When we break out of the for-loop, the wizard should be at the terminal
	// node that represents the string we're trying to insert.
	wizard->count++;
	return root;
}



// removes punctuation from a string
char *removePunctuation(char *string)
{
	int i, j, lengthNoPunct = 0;
	// i keeps track of string index, j keeps track of new string index
	char *newString;

	if(string == NULL)
	{
		printf("something wrong happened. line: %d\n", __LINE__);
		return NULL;
	}

	i = 0;
	while(string[i] != '\0')
	{
		if(isalpha(string[i]))
		{
			lengthNoPunct++;
			printf("%c", string[i]);
		}

		i++;
	}

	newString = malloc(sizeof(char) * (lengthNoPunct+1));
	i = 0;
	j = 0;
	while(string[i] != '\0')
	{
		if(isalpha(string[i]))
			newString[j++] = string[i];

		i++;
	}

	newString[lengthNoPunct+1] = '\0';

	return newString;
}

int getLargestCount(TrieNode *root)
{
	int i;
	int curCount;
	int tempCount;
	if (root == NULL)
		return 0;

	curCount = root->count;

	for(i = 0; i < 26; i++)
	{
		if (root->children[i] != NULL)
		{
			tempCount = getLargestCount(root->children[i]);
			if(tempCount > curCount)
				curCount = tempCount;
		}
	}

	return curCount;
}







int main(int argc, char **argv)
{
	//(1) capture the names of the corpus and input files (passed as command line arguments), (2) call the 
	// buildTrie() function, (3) call the processinputFileName() function, (4) call the destroyTrie() function, and (5) 
	// return zero.

	char *corpusFileName, *inputFileName, str[MAX_CHARACTERS_PER_WORD];
	FILE *corpusFile, *inputFile;
	TrieNode *root, *lastNode;
	corpusFileName = argv[1];
	inputFileName = argv[2];

	if((corpusFile = fopen(corpusFileName, "r")) == NULL)
	{
		printf("Error opening");
		return 1;
	}

	if((inputFile = fopen(inputFileName, "r")) == NULL)
	{
		printf("Error opening");
		fclose(corpusFile);
		return 1;
	}

	root = buildTrie(corpusFileName);

	fgets(str, MAX_CHARACTERS_PER_WORD, inputFile);

	while(str[0] != EOF)
	{
		if(str[0] == '!')
		{
			printTrie(root, 0);
		}
		else if(str[0] != '@')
		{
			if(containsWord(root, str))
			{
				lastNode = getNode(root, str);
				printf("%s\n", str);
				printTrie(lastNode, 1);
			}
		}
		else
		{
			
		}

		fgets(str, MAX_CHARACTERS_PER_WORD, inputFile);
	}

	
	


	destroyTrie(root);

	fclose(corpusFile);
	fclose(inputFile);

	return 0;
}
