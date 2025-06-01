/*
Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number 
of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When 
either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
*/

#include <stdio.h>

#define		TABSTOP		8
#define		MAXLen		100

int entab(char line[], char tempString[]);
int fillLine(char line[], int len);
int clearLine(char line[]);

int main()
{
	char tempString[MAXLen] = "";
	char line[MAXLen] = "Hello    ";
	int length = 0;
	int entabLine = 0;
	while((length = fillLine(line, MAXLen)) != 0)
	{
		if ((entabLine = entab(line, tempString)) == 0)
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

int entab(char line[], char tempString[])
{
	int line_counter = 0;
	int temp_counter = 0;
	int spaces = 0;
	int tabs = 0;
	while(line[line_counter] != '\0')
	{
		if (line[line_counter] != ' ' )
		{
			tempString[temp_counter++] = line[line_counter++];
		}
		else
		{
			while(line[line_counter] == ' ')
			{
				spaces++;
				line_counter++;
			}
			tabs = spaces / TABSTOP;
			spaces = spaces -  (tabs * TABSTOP);
			for(; tabs > 0; tabs--)
				tempString[temp_counter++] = '\t';
			for(; spaces > 0; spaces--)
				tempString[temp_counter++] = ' ';
			spaces = tabs = 0;
		}
	}
	
	tempString[temp_counter] = '\0';
	return 0;
}
