#include <stdio.h>

int lineLen(char line[]);
int copy(char line[], char longest_line[], int len);

#define MAXLength 1000

int main()
{
	char longest_line[MAXLength] = "";
	char line[MAXLength] = "";
	int length = 0;
	int MAXlen = 0;
	while(fgets(line, MAXLength, stdin) != NULL)
	{
		length = lineLen(line);
		if (length >= MAXlen)
			MAXlen = length;
		copy(line, longest_line, MAXlen);
	}
	printf("\nLongest Line: %s\nLength: %d\n", longest_line, MAXlen-1);
	return 0;
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

int copy(char line[], char longest_line[], int len)
{
	int counter = 0;
	while(counter < len)
	{
		longest_line[counter] = line[counter];
		counter++;
	}
	return 0;
}