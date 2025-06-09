/*
Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in 
s1 that matches any character in the string s2.
*/

void squeeze(char s[], int c);
int mysqueeze(char s[], int c, char new_string[]);

int main()
{
	char s[] = "";
	char new_string[] = "";
	int c = '';
	printf("The new string : %s\n", mysqueeze(s, c, new_string));
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

int mysqueeze(char s[], int c, char new_string[])
{
	int i = 0;
	while (s[i] != '\0')
	{
		
	}
	
	return 0;
}