#include <stdio.h>

int updateline(char line[], int len);
int lineLen(char line[]);
int copy(char line[], char longest_line[]);

#define MAXLength 100

int main()
{
	char longest_line[MAXLength] = "";
	char line[MAXLength] = "";
	int length = 0;
	int MAXlen = 0;
	while((length = updateline(line, MAXLength)) != 0)
	{
		//length = lineLen(line);
		/*if (line[length - 1] == '\n') {
            line[length - 1] = '\0';
            length--;
        }*/
		if (length >= MAXlen)
			MAXlen = length;
		copy(line, longest_line);
	}
	printf("\nLongest Line: %s\nLength: %d\n", longest_line, MAXlen-1);
	return 0;
}

int updateline(char line[], int len)
{
	// line[0] = '\0';  
	int c = ' ';
	int counter = 0;
	while ((c = getchar()) != EOF)
	{
		printf("Char # %d: %c\n", counter,c );
		if (counter == len) return counter;
		line[counter++] = c;
	}
	printf("Line : %s\nCounter: %d\n", line, counter);
	return counter;
}

int lineLen(char line[])
{
	int counter = 0;
	int len = 0;
	while (line[counter] != '\0')
	{
		len++;
		counter++;
	}
	return len;

}

int copy(char line[], char longest_line[])
{
	// longest_line[0] = '\0';
	int counter = 0;
	while((longest_line[counter] = line[counter]) != '\0')
		counter++;
	return 0;
}