// Sean Szumlanski
// COP 3502, Spring 2023

// ===========================
// StringMuncher: testcase02.c
// ===========================
// This test case is a simple boundary check to help ensure the hoursSpent()
// function is implemented correctly.


#include <stdio.h>
#include "StringMuncher.h"

int main(void)
{
	if (hoursSpent() <= 0.0)
		printf("fail whale :(\n");
	else
		printf("Hooray!\n");

	return 0;
}
