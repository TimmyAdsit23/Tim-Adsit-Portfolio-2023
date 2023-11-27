// Sean Szumlanski
// COP 3502, Spring 2023

// ============================
// TriePrediction: UnitTest17.c
// ============================
// Tests the functionality of newNodeCount().


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TriePrediction.h"


void failwhale(char *err_msg)
{
	printf("fail whale :( --- %s\n", err_msg);
	exit(0);
}

// This acts as the main() function for this test case.
int unit_test(int argc, char **argv)
{
	TrieNode *root, *result, *solution;
	root = buildTrie("corpus01.txt");

	if (newNodeCount(root, "") != 0)
		failwhale("fails with empty string");

	if (newNodeCount(root, "cherries") != 3)
		failwhale("fails with \"cherries\"");

	if (newNodeCount(root, "real") != 0)
		failwhale("fails with \"real\"");

	if (newNodeCount(root, "really") != 0)
		failwhale("fails with \"really\"");

	if (newNodeCount(root, "realism") != 3)
		failwhale("fails with \"realism\"");

	if (newNodeCount(NULL, "pie") != 4)
		failwhale("fails with \"pie\" and NULL root");

	root = destroyTrie(root);

	printf("Success!\n");

	return 0;
}
