/*
Exercise 1-20. Write a program detab that replaces tabs in the input with the proper 
number of blanks to space to the next tab stop. Assume a fixed set of tab stops, 
say every n columns. Should n be a variable or a symbolic parameter?
*/

#include <stdio.h>

#define		TABSTOP		8
#define		MAXLen		100

int detab(char line[], char tempString[], int len);
int fillLine(char line[], int len);
int clearLine(char line[]);

int main()
{
	char tempString[MAXLen*8] = "";
	char line[MAXLen] = "";
	int length = 0;
	int detabLine = 0;
	while((length = fillLine(line, MAXLen)) != 0)
	{
		if ((detabLine = detab(line, tempString, length)) == 0)
			printf("%s\n", tempString);
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

int detab(char line[], char tempString[], int len)
{
	int counter = 0; // to follow Line
	int column = 0; // To follow tempString
	clearLine(tempString);
	while (line[counter] != '\0')
	{
		// if(counter % TABSTOP != 0) tempString[counter] = line[counter];
		if (line[counter] != '\t') 
			tempString[column++] = line[counter++];
		else
			for (int i = column; i < TABSTOP; i++)
				tempString[column++] = ' ';
		//column = 0;
	}
	printf("%d %c",column, tempString[column]);
	return 0;
}
