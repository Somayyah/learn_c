/*
Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string 
s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. 
(The standard library function strpbrk does the same job but returns a pointer to the location.)
*/

#include <stdio.h>

#define		STANDARD_NUMBER_OF_CHARS	256
int any(char s1[], char s2[]);

int main()
{
	char s1[] = "770Hello, world!\n";
	char s2[] = "10";
	printf("Position is : %d\n", any(s1, NULL));
	return 0;
}

int any(char s1[], char s2[])
{
	if (!(s2 == NULL || s1 == NULL))
	{
		int i;
		unsigned char exists[STANDARD_NUMBER_OF_CHARS] = {0};
		
		for ( i = 0; s2[i] != '\0';i++)
			exists[(unsigned char)s2[i]] = 1;
		
		for (i = 0; s1[i] != '\0'; i++)
			if (exists[(unsigned char)s1[i]]) return (i);
	}
	return -1;
}