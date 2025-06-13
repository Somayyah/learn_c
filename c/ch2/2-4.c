/*
Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in 
s1 that matches any character in the string s2.
*/

#include <stdio.h>

int squeeze(char s[], int c);
int mysqueeze(char s[], char s2[]);
int myreplace(char s[], char s2[]);

int main()
{
	char s[] = "ababababab";
	char s2[] = "aa"; // baaa
	int x = 'x';
	int c = mysqueeze(s, s2);
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
	int i , j , k;
	i = j = k = 0;

	while (s2[k] != '\0' && s[i] != '\0')
	{
		while (s[i] != '\0')
		{
			if (s[i] != s2[k])
				s[j++] = s[i];
			i++;
		}
		
		s[j] = '\0';
		k++;

		i = j = 0;
	}

	return 0;
}

/*
replace each character in `s1` that matches any character in `s2` with a specific replacement 
character `X`, but only if `X` is not already present in `s1`"
*/

int myreplace(char s[], char s2[], int x)
{
	int i , j , k;
	i = j = k = 0;

	while (s2[k] != '\0' && s[i] != '\0')
	{
		while (s[i] != '\0')
		{
			if (s[i] != s2[k])
				s[j++] = s[i];
			i++;
		}
		
		s[j] = '\0';
		k++;

		i = j = 0;
	}
	
	return 0;

}

/*

Assume X = 
| Test Case # | `s1` (Input String)      | `s2` (Characters to Delete) | Expected Result                                  | 
| ----------- | ------------------------ | --------------------------- | ------------------------------------------------ | 
| 1           | `"hello world"`          | `"aeiou"`                   | `"hll wrld"`                                     | ✅
| 2           | `"banana"`               | `"n"`                       | `"baaa"`                                         | ✅
| 3           | `"abcdefg"`              | `"xyz"`                     | `"abcdefg"`                                      | ✅
| 4           | `"the quick brown fox"`  | `" "`                       | `"thequickbrownfox"`                             | ✅
| 5           | `"1234567890"`           | `"2468"`                    | `"135790"`                                       | ✅
| 6           | `"AaBbCc"`               | `"abc"`                     | `"AABBC"` (or `"AABBCC"` in case-sensitive test) | ✅
| 7           | `"repeat repeat repeat"` | `"re"`                      | `"pat pat pat"`                                  | ✅
| 8           | `""` (empty string)      | `"abc"`                     | `""`                                             | ✅
| 9           | `"nothing"`              | `""` (empty `s2`)           | `"nothing"`                                      | ✅
| 10          | `""`                     | `""`                        | `""`                                             | ✅
| 11          | `"aaaaa"`                | `"a"`                       | `""`                                             | ✅
| 12          | `"abcABC"`               | `"ABC"`                     | `"abc"`                                          | ✅
*/