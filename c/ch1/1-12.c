/*
	Exercise 1-12. Write a program that prints its input one word per line.
*/


#include <stdio.h>

// Are we within the boundary of multiple whitespace characters?
#define IN	1  
#define OUT 0

int main()
{
	int c, state, flag;
	c = flag = 0;
	state = OUT;
	
	while ((c = getchar()) != EOF) 
	{
		if (c == ' ' || c == '\n' || c == '\t' )
		{
			if (state == OUT && flag != 0 ) putchar('\n');
			state = IN;
		}
		
		else 
		{
			flag = 1;
			putchar(c);
			state = OUT;
		}
	}
	
	if (state == OUT && flag ) {
		putchar('\n');
	}

	return 0;
}