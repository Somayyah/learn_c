/*
Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits 
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits 
are 0 through 9, a through f, and A through F.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_UNSIGNED_INT 4294967295
unsigned int htoi(char h[]);

int main() {
	char input[] = "0XAAA";
	printf("Result : %d\n", htoi(input));
    return 0;
}

unsigned int htoi(char h[])
{
	int i, n, digit, digit_found;
	unsigned int final_value = 0;
	digit_found = digit = i = n = 0;
	if(h[i] == '\0')
	{
		printf("Error - Empty Input\n");
		exit(-1);
	}
	while(h[i] != '\0')
	{
		if( h[i] == '0' && (h[i+1] == 'x' || h[i+1] == 'X')) 
			if (digit_found == 0) 
				i += 2;
			else
			{
				printf("Error - Wrong formatting\n");
				exit(-1);
			}
		digit = 0;
		// int = ∑ (digitₙ × 16ⁿ)
		if( ( h[i] >= '0' && h[i] <= '9' ) || (h[i] >= 'a' && h[i] <= 'f') || (h[i] >= 'A' && h[i] <= 'F' ) || h[i] == 'x' || h[i] == 'X')
		{
			if ( ( h[i] >= '0' && h[i] <= '9' ) )
				digit = h[i] - '0';
			else if ((h[i] >= 'a' && h[i] <= 'f'))
				digit = h[i] - 'a' + 10;
			else
				digit = h[i] - 'A' + 10;
			if (final_value > (MAX_UNSIGNED_INT - digit) / 16) {
				printf("Overflow!!\n");
				exit(-1);
			}

			final_value = final_value * 16 + digit;
			i++;
			digit_found++;

		} else 
		{
			printf("Error - Illegal characters found\n");
			exit(-1);
		}
	}
	return final_value;
}

/*
| Input             | Expected Output | Notes                                     |
|------------------|-----------------|--------------------------------------------|
| ""               | 0 or error      | Empty string                               | ✅ 
| "0"              | 0               | Simple case                                | ✅
| "1"              | 1               | Basic digit                                | ✅
| "a"              | 10              | Lowercase hex                              | ✅
| "A"              | 10              | Uppercase hex                              | ✅
| "f"              | 15              | Lowercase max hex digit                    | ✅
| "F"              | 15              | Uppercase max hex digit                    | ✅
| "10"             | 16              | Two-digit number                           | ✅
| "1A"             | 26              | Mixed digits and letters                   | ✅
| "0x1A"           | 26              | With lowercase prefix                      | ✅
| "0X1A"           | 26              | With uppercase prefix                      | ✅
| "deadbeef"       | 3735928559      | Meme hex (lowercase)                       | ✅
| "0xDEAD"         | 57005           | Prefix and uppercase                       | ✅
| "ABC123"         | 11256099        | Mixed case                                 | ✅
| "0x"             | 0 or error      | Prefix only, no digits                     | ✅
| "0x1.2"          | Error           | Invalid: decimal point                     | ✅
| "0xG1"           | Error           | Invalid: 'G' not a hex digit               | ✅
| "xyz"            | Error           | No valid hex characters                    | ✅
| "0x-1"           | Error           | Negative sign not allowed in hex           | ✅
| " 1A"            | Error           | Leading space: undefined unless trimmed    | 
| "1A "            | Error           | Trailing space                             | 
| "0x1A3Z"         | Error           | Invalid trailing character                 | ✅
| "0X7FFFFFFF"     | 2147483647      | Max signed 32-bit                          | ✅
| "FFFFFFFF"       | 4294967295      | Max unsigned 32-bit                        | ✅
| "FFFFFFFFF"      | Overflow/error  | Beyond unsigned 32-bit range               | ✅
*/