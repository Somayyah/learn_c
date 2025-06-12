/*
Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in 
s1 that matches any character in the string s2.
*/

#include <stdio.h>

int squeeze(char s[], int c);
int mysqueeze(char s[], char s2[]);

int main()
{
	char s[] = "hello world";
	char s2[] = "aeiou";
	int c = squeeze(s, 'l');
	printf("The new string : %s\n", s);
	return 0;
}

/* squeeze: delete all c from s */
int squeeze(char s[], int c)
{
	int i, j;
	i = j = 0;
	
	while (s[i] != '\0')
	{
		if (s[i] != c)
			s[j++] = s[i];
		i++;
	}
		s[j] = '\0';
	return 0;
}

int mysqueeze(char s[], char s2[])
{
	int i , j;
	i = j = 0;
	while (s[i] != '\0')
	{
		while (s2[j] != '\0')
			if (s[i] != s2[j++]) s[i++] = s2[++i];
		i++;
	}
	s[i] = '\0';
	
	return 0;
}

/*
| Test Case # | `s1` (Input String)      | `s2` (Characters to Delete) | Expected Result                                  | Notes                       |
| ----------- | ------------------------ | --------------------------- | ------------------------------------------------ | --------------------------- |
| 1           | `"hello world"`          | `"aeiou"`                   | `"hll wrld"`                                     | Remove all vowels           |
| 2           | `"banana"`               | `"n"`                       | `"baaa"`                                         | Repeated chars removed      |
| 3           | `"abcdefg"`              | `"xyz"`                     | `"abcdefg"`                                      | No matches                  |
| 4           | `"the quick brown fox"`  | `" "`                       | `"thequickbrownfox"`                             | Remove all spaces           |
| 5           | `"1234567890"`           | `"2468"`                    | `"135790"`                                       | Digits removal              |
| 6           | `"AaBbCc"`               | `"abc"`                     | `"AABBC"` (or `"AABBCC"` in case-sensitive test) | Case sensitivity test       |
| 7           | `"repeat repeat repeat"` | `"re"`                      | `"pat pat pat"`                                  | Multiple matches, scattered |
| 8           | `""` (empty string)      | `"abc"`                     | `""`                                             | Empty `s1`                  |
| 9           | `"nothing"`              | `""` (empty `s2`)           | `"nothing"`                                      | Empty `s2`, no removals     |
| 10          | `""`                     | `""`                        | `""`                                             | Both empty                  |
| 11          | `"aaaaa"`                | `"a"`                       | `""`                                             | Complete removal            |
| 12          | `"abcABC"`               | `"ABC"`                     | `"abc"`                                          | Uppercase deletion only     |
*/