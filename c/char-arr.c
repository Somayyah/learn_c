#include <stdio.h>

int getline(char line[]);
int copy();

#define MAXLength 1000

int main()
{
	char longest_line[MAXLength] = "";
	char line[MAXLength] = "";
	int length = 0;
	int MAXlen = 0;
	while(fgets(line, MAXLength, stdin) != NULL)
	{
		length = getline(line);
		if (length >= MAXlen)
			MAXlen = length;
		longest_line = line;
	}
	return 0;
}

int getline(char line[])
{
	
}

int copy()
{
	
}