/*
Exercise 1-20. Write a program detab that replaces tabs in the input with the proper 
number of blanks to space to the next tab stop. Assume a fixed set of tab stops, 
say every n columns. Should n be a variable or a symbolic parameter?
*/

#include <stdio.h>

#define		TABSTOP		4
#define		MAXLen		100

int detab(char line[], char tempString[]);
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
		if ((detabLine = detab(line, tempString)) == 0)
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

int detab(char line[], char tempString[])
{
	int line_counter = 0;
	int temp_counter = 0;
	int spaces = 0;
	while(line[line_counter] != '\0')
	{
		if (line[line_counter] != 9 )
		{
			tempString[temp_counter++] = line[line_counter++];
		}
		else
		{
            spaces = (TABSTOP - (temp_counter % TABSTOP)) % TABSTOP;

            if (spaces == 0) spaces = TABSTOP;

            for (; spaces > 0; spaces--)
                tempString[temp_counter++] = '*';

            line_counter++;	
		}
	}
	
	tempString[temp_counter] = '\0';  // Null-terminate the result
	return 0;
}
