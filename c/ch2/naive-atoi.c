
#include <stdio.h>

int atoi(char s[]);

int main()
{
	char s[] = " 42";
	printf("Number : %d\n", atoi(s));
	return 0;
}

/* atoi: convert s to integer */

int atoi(char s[])
{
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

/*
-ve or +ve numbers?
White spaces?
non numeric chars?
overflow?!
*/