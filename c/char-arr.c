#include <stdio.h>

// C language doesn't support strings as a datatype

int getline(int MAXLength, char longest_line[]);
int copy();

#define MAXLength 1000

int main()
{
	char longest_line[MAXLength] = "";
	char line[MAXLength] = "";
	int length = 0;
	int MAXlen = 0;
	getline(MAXLength, line);
	return 0;
}

int getline(int MAXLength, char longest_line[])
{
	while ((c = getchar()) != EOF )
	{
		
	}
	return 0;
}

int copy()
{
	
}