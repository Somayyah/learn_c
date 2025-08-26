/*
	Exercise 1-11. How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?
*/

#include <stdio.h>
#include <ctype.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
int main()
{
	int c, state;
	long nl, nw, nc;
	state = OUT;
	nl = 1;
	nw = nc = 0;
	
	while ((c = getchar()) != EOF) 
	{
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t' || !isalnum(c))
			state = OUT;
		else if (state == OUT) 
		{
			state = IN;
			++nw;
		}
	}
	printf("%ld %ld %ld\n", nl, nw, nc);
	return 0;
}