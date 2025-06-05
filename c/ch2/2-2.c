/*
Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
s[i] = c;
*/

#include <stdio.h>

int main()
{
	int c, lim = 5;
	for (int i=0; i < lim-1 ; ++i)
	{
		if (c=getchar()) != '\n' && c != EOF)
			s[i] = c;
	}
	return 0;
}