/*
	Exercise 1-8. Write a program to count blanks, tabs, and newlines.
*/

#include <stdio.h>

int main()
{
	int c, nt, nl, nb; // input, number of tabs, lines and blanks
	nt = nl = nb = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
			++nl;
		else if (c == '\t')
			++nt;
		else if (c == ' ')
			++nb;
	}
	printf("Blanks : %d\nTabs : %d\nNewlines : %d\n", nb, nt, nl);
	return 0;
}