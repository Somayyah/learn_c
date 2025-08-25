/*
	Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
*/

#include <stdio.h>

#define 	TRUE	1
#define		FALSE	0
int main()
{
	int flag = FALSE;
	int c = getchar();
	while (c != EOF)
	{
		putchar(c);
		if (c == ' ' || c == '\t' || c == '\n') flag = TRUE;
		while( ((c = getchar()) == ' ' || c == '\t' || c == '\n') && flag == TRUE)
			;
		flag = FALSE;
	}
	return 0;
}