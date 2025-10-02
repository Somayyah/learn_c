/*
	Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.
*/

#include <stdio.h>

#define 	LOWEST		0			// First character ' '
#define		HIGHEST		127			// Last character '~' + 1

int main()
{
	int c, c_count[HIGHEST];
	c = 0;
	
	for (int i = LOWEST; i < HIGHEST; ++i)
		c_count[i] = 0;
	
	while((c = getchar()) != EOF) 
	{
		if (c >= LOWEST && c <= HIGHEST)
			c_count[c]++;
	}
	
	putchar('\n');
	
	for(int i = LOWEST; i < HIGHEST; i++)
		if (c_count[i] != 0)
		{
			if (i == 9)
				printf("HT 	: ");
			else if (i == 10)
				printf("LF 	: ");
			else if (i == 32)
				printf("SPACE : ");
			else printf("%c : ", i);
			
			for (int j = 0; j < c_count[i] ; j++ )
				putchar('*');
			putchar('\n');
		}
		
	return 0;
}
