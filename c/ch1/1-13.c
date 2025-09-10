/*
	Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/

/*Horizontal*/
 
#include <stdio.h>

#define 	MAX_NUMBER_OF_LETTERS		21

int main()
{
	int c, c_count[MAX_NUMBER_OF_LETTERS], nc;
	c = nc = 0;
	
	for (int i = 0; i < MAX_NUMBER_OF_LETTERS; ++i)
		c_count[i] = 0;
	
	while((c = getchar()) != EOF) 
	{
		if ( c != '\n' && c != ' ' && c != '\t' )
			nc++;
		else 
		{
			if (nc < MAX_NUMBER_OF_LETTERS - 1)
				++c_count[nc];
			else c_count[MAX_NUMBER_OF_LETTERS - 1]++; // Any word longer than 20 is counted here.
			nc = 0;
		}
	}

	if ( nc != 0 )
		++c_count[nc];
	
	putchar('\n');
	
	for(int i = 1; i < MAX_NUMBER_OF_LETTERS; i++)
		if (c_count[i] != 0)
		{
			printf("%d : ", i);
			for (int j = 0; j < c_count[i] ; j++ )
				putchar('*');
			putchar('\n');
		}
	
	return 0;
}