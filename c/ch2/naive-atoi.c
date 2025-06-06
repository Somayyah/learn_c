
#include <stdio.h>
#include <stdlib.h>

#define		INT_MAX 	2147483647
#define 	INT_MIN 	-2147483648

int naive_atoi(char s[]);
int robust_atoi(char s[]);

int main()
{
	char s[] = "6666333333333333333333333333333333333";
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
	int i, n, sign = 1, repeated_sign = 0, printed_digit = 0;
	n = i = 0;
	while(s[i] != '\0')
	{
		if( s[i] == '-' || s[i] == '+' )
		{
			if ( repeated_sign == 0 && printed_digit == 0)
			{
				sign = ( s[i] == '-' ) ? (-1) : 1;
			}
			else
			{
				printf("Invalid Input\n");
				exit(-1);
			}	
			i++;
			repeated_sign = 1;
		}
		if ( s[i] != ' ' && s[i] != '\t' )
		{
			if ( s[i] >= '0' && s[i] <= '9' )
			{
				int digit = s[i] - '0';
				if (sign == 1 && ( n > (INT_MAX - digit) / 10 )) {
					printf("Overflow detected\n");
					exit(-1);
				}
				if (sign == -1 && (n > (INT_MIN - digit) / 10)) {
					printf("Underflow detected\n");
					exit(-1);
				}

				n = 10 * n + digit;

				i++;
				printed_digit++;
			} else
			{
				printf("Invalid Input\n");
				exit(-1);
			}
		} else 
		{
			if ( printed_digit >= 1 || repeated_sign == 1)
			{
				printf("Invalid Input\n");
				exit(-1);
			}
			i++;	
		}
	}
	return n * sign;
}

/*
| Input                     | Expected Output | Notes                        |
| ------------------------- | --------------- | ---------------------------- |
| `"123"`                   | `123`           | Normal case                  | ✅
| `"-123"`                  | `-123`          | -ve number                   | ✅ 
| `"   +456"`               | `456`           | Leading whitespace + sign    | ✅ 
| `"  -42abc"`              | `-42`           | Stop at non-digit            | ✅ 
| `"abc123"`                | `0`             | Invalid start                | ✅ 
| `""`                      | `0`             | Empty string                 | ✅ 
| `"999999999999999999999"` | ??              | Overflow?!                   | ✅
| `" + 123"`                | `0` or error    | Space after sign = invalid   | ✅ 
| `"--123"`                 | `0` or error    | Double sign = invalid        | ✅ 
| `"+-123"`                 | `0` or error    | Mixed signs = invalid        | ✅ 
| `"-12 3"`                 | `0` or error    | white space in the middle    | ✅ 
| `"-12+3"`                 | `0` or error    | Sign in the middle           | ✅ 
*/