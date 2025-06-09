/*
Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in 
s1 that matches any character in the string s2.
*/

int main()
{
	char s[] = "";
	int c = '';
	printf("The new string : %s\n", mysqueeze(s, c));
	return 0;
}

/* squeeze: delete all c from s */
void squeeze(char s[], int c)
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++)
	if (s[i] != c)
	s[j++] = s[i];
	s[j] = '\0';
}

int mysqueeze(char s[], int c)
{
	int i = 0;
	while (s[i] != '\0')
	{
		
	}
	
	return 0;
}