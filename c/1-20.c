/*
Exercise 1-20. Write a program detab that replaces tabs in the input with the proper 
number of blanks to space to the next tab stop. Assume a fixed set of tab stops, 
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
	int length = 0;
	int detabLine = 0;
	while((length = fillLine(line, MAXLen)) != 0)
	{
		if ((detabLine = detab(line, length)) == 0)
			printf("%s\n", line);
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

int detab(char line[], int len)
{
	char tempString[len] = "";
	int counter = 0;
	// int column = 0;
	while (line[counter] != '\0')
	{
		// if(counter % TABSTOP != 0) tempString[counter] = line[counter];
		if (line[counter] != '\t') 
			
			
		counter++;
		column++;
	}
	return 0;
}
