/*
Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines 
after the last non-blank character that occurs before the n-th column of input. Make sure your 
program does something intelligent with very long lines, and if there are no blanks or tabs 
before the specified column.
*/

#include <stdio.h>

#define		COLUMN		3
#define		MAXLen		1000

int fold(char line[], char tempString[]);
int fillLine(char line[], int len);
int clearLine(char line[]);

int main()
{
	char tempString[MAXLen] = "";
	char line[MAXLen] = "";
	int length = 0;
	int entabLine = 0;
	while((length = fillLine(line, MAXLen)) != 0)
	{
		if ((entabLine = fold(line, tempString)) == 0)
			printf("%s\n", tempString);
		clearLine(tempString);
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

int fold(char line[], char tempString[])
{
	int line_counter = 0;
	int temp_counter = 0;
	int edge = 1;
	while(line[line_counter] != '\0')
	{
		if(line_counter != 0) 
			edge = line_counter % COLUMN;
		if ( edge != 0 )
			tempString[temp_counter++] = line[line_counter++];
		else
		{
			if (tempString[temp_counter - 1] != '\t' && tempString[temp_counter] != ' ')
				tempString[temp_counter++] = '-';
			tempString[temp_counter++] = '\n';
			tempString[temp_counter++] = line[line_counter++];
		}
	}
	tempString[temp_counter] = '\0';
	return 0;
}
