/*
Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
s[i] = c;
*/

#include <stdio.h>

int main()
{
	int i, c, lim = 5;
	char s[lim];
	for (;i < lim-1 ; ++i)
	{
		c = getchar();
		if (c == '\n')
			break;
		if(c == EOF)
			break;
		s[i] = c;
	}
	s[i] = '\0';
	printf("Result: %s\n", s);
	return 0;
}