/*
	Exercise 1-17. Write a program to print all input lines that are longer than 80 characters..
*/

#include <stdio.h>

#define		MAXLEN		1000 	// Maximum length of a sentence.

int main()
{
	int c = 0, counter = 0;
	char line[MAXLEN];
	
	
	while((c = getchar()) != EOF) 
	{
		if (c != '\n') counter++;
		if (counter == 80)
	}

	return 0;
}
