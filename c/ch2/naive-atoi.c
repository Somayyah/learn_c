
#include <stdio.h>

int atoi(char s[]);
int robust_atoi(char s[]);

int main()
{
	char s[] = "11111";
	printf("Number : %d\n", robust_atoi(s));
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

int robust_atoi(char s[])
{
	int flag = 1, i, n, length;
	i = length = n = 0;
	
	while( s[i] != '\0')
	{
		if ( s[i] >= '0' && s[i] <= '9')
		{
			n = 10 * n + (s[i++] - '0');
		}
		else if (s[i] == ' ' || s[i] == '\t')
			i++;
		else if (s[i] == '-' || s[i] == '+') 
		{
			flag = (-1);
			i++;
		}
		else
		{
			printf("Not a number\n");
			return 0;
		}
	}

	return n * flag;
}

/*
-ve or +ve numbers?
White spaces?
sign before / after spaces?
non numeric chars?
overflow?!
*/