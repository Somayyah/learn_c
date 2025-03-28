/*
Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number 
of blanks to space to the next tab stop. Assume a fixed set of tab stops, 
say every n columns. Should n be a variable or a symbolic parameter?
*/

#include <stdio.h>

#define		TABSTOP		8
#define		MAXLen		100

int detab(char line[], int len);
int fillLine(char line[], int len);
int clearLine(char line[]);

int main()
{
	char line[MAXLen] = "";
	char detabLine[MAXLen] = "";
	while((length = fillLine(line, MAXLen)) != 0)
	{
		detabLine = detab(line, length);
		printf("%s\n", detabLine);
	}
	return 0;
}


int fillLine(char line[], int len)
{
	clearLine(line);
	int c , counter;
	c = counter = 0;
	while (((c = getchar()) != EOF) && c != '\n')
	{
		if (counter == len) return counter;
		line[counter++] = c;
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

char[] detab(char line[], int len)
{
	char detabedLine[len] = 0;
	return 0;
}
