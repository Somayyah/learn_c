#include <stdio.h>

int updateline(char line[], int len);
int lineLen(char line[]);
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
		//length = lineLen(line);
		/*if (line[length - 1] == '\n') {
            line[length - 1] = '\0';
            length--;
        }*/
		if (length >= MAXlen){
			MAXlen = length;
			copy(line, longest_line);
		}
		printf("Line: %s\nLongest_line: %s\nMaxLen: %d\nLength: %d\n", line, longest_line, MAXlen, length);
	}
	printf("\nLongest Line: %s\nLength: %d\n", longest_line, MAXlen);
	return 0;
}

int updateline(char line[], int len)
{
	clearLine(line);
	int c = ' ';
	int counter = 0;
	while (((c = getchar()) != EOF) && c != '\n')
	{
		// printf("Char # %d: %c\n", counter,c );
		if (counter == len) return counter;
		line[counter++] = c;
	}
	// printf("Line : %s\nCounter: %d\n", line, counter);
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
	clearLine(longest_line);
	int counter = 0;
	while((longest_line[counter] = line[counter]) != '\0')
		counter++;
	return 0;
}