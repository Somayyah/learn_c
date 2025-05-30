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
	char tempString[MAXLen] = "";
	char line[MAXLen] = "";
	int length = 0;
	int detabLine = 0;
	while((length = fillLine(line, MAXLen)) != 0)
	{
		printf("Line out : %s,\tLength : %d\n", line, length);
		if ((detabLine = detab(line, tempString, length)) == 0)
			printf("%s\n", tempString);
		//clearLine(line);
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
	printf("Line in : %s\t, counter : %d\n", line, counter);
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
	int line_counter = 1;
	int temp_counter = 0;
	while(line[line_counter - 1] != '\0')
	{
		if (line[line_counter - 1] != '\t')
		{
			tempString[temp_counter] = line[line_counter - 1];
			line_counter++;
			temp_counter++;
		}
		if (line[line_counter - 1] == '\t')
		{
			for (;temp_counter < (line_counter - 1 - TABSTOP) ; )
				tempString[temp_counter++] = '*';
		}
	}
	return 0;
}
