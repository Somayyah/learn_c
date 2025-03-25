/*
Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print 
the length of arbitrary long input lines, and as much as possible of the text.
*/

#include <stdio.h>

int updateline(char line[], int len);
int copy(char line[], char longest_line[]);
int clearLine(char line[]);

#define MAXLength 100

int main()
{
	char longest_line[MAXLength] = "";
	char line[MAXLength] = "";
	int length = 0;
	int MAXlen = 0;
	while((length = updateline(line, MAXLength)) != 0)
	{
		if (length >= MAXlen){
			MAXlen = length;
			copy(line, longest_line);
		}
	}
	if (MAXlen > 0) 
		printf("\nLongest Line: %s\nLength: %d\n", longest_line, MAXlen);
	return 0;
}

int updateline(char line[], int len)
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

int copy(char line[], char longest_line[])
{
	clearLine(longest_line);
	int counter = 0;
	while((longest_line[counter] = line[counter]) != '\0')
		counter++;
	return 0;
}