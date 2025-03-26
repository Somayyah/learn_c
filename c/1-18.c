/*
Exercise 1-18. Write a program to remove trailing blanks and tabs from each 
line of input, and to delete entirely blank lines.
*/

#include <stdio.h>

int updateline(char line[], int len);
int clearLine(char line[]);

#define MAXLength 100

int main()
{
	char line[MAXLength] = "";
	int length = 0;
	int MAXlen = 0;
	while((length = updateline(line, MAXLength)) != 0)
	{
		printf("%s\n", line);
	}
	return 0;
}

int updateline(char line[], int len)
{
	clearLine(line);
	int c , counter;
	c = counter = 0;
	while (((c = getchar()) != EOF) && c != '\n')
	{
		if (c != '\t' && c != ' '){
			if (counter == len) return counter;
			line[counter++] = c;
		}
	}
	return counter;
}

int clearLine(char line[])
{
	int counter = 0;
	while(line[counter] != '\0')
	{
		line[counter] = '\0';
		counter++;
	}
	return 0;
}