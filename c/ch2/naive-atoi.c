
#include <stdio.h>

int naive_atoi(char s[]);
int robust_atoi(char s[]);

int main()
{
	char s[] = "11111";
	printf("Number : %d\n", robust_atoi(s));
	return 0;
}

/* atoi: convert s to integer */

int naive_atoi(char s[])
{
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

int robust_atoi(char s[])
{
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}

/*
| Input                     | Expected Output | Notes                        |
| ------------------------- | --------------- | ---------------------------- |
| `"123"`                   | `123`           | Normal case                  |
| `"-123"`                  | `-123`          | -ve number                   |
| `"   +456"`               | `456`           | Leading whitespace + sign    |
| `"  -42abc"`              | `-42`           | Stop at non-digit            |
| `"abc123"`                | `0`             | Invalid start                |
| `""`                      | `0`             | Empty string                 |
| `"999999999999999999999"` | ??              | Overflow?!                   |
| `" + 123"`                | `0` or error    | Space after sign = invalid   |
| `"--123"`                 | `0` or error    | Double sign = invalid        |
| `"+-123"`                 | `0` or error    | Mixed signs = invalid        |
*/