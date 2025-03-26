/*
Exercise 1-19. Write a function reverse(s) that reverses the character string s. 
Use it to write a program that reverses its input a line at a time.
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
		if (length >= 80){
			MAXlen = length;
			printf("%s\n", line);
		}
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