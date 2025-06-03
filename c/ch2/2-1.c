/*
Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, 
by printing appropriate values from standard headers and by direct computation. Harder if you compute them: 
determine the ranges of the various floating-point types.
*/

#include <limits.h>
#include <stdio.h>

int	to_power(int x);

int main()
{
	//printf("Ranges according to standard headers:");
	//for(int i = 0; i >= 64 ; i++)
		//printf("i : %d", i);
	
	//printf("Ranges calculated:");
	for(int i = 0 ; i <= 10 ; i++)
		printf("2 ^ %d = %d\n", i , to_power(i));
	// printf("Range for %s : Min = %d, Max = %d", "char" , -（2 （ (sizeof(char) * 8 ）-1));
	return 0;
}

int	to_power(int x)
{
	int result = 1;
	for (int i = 0; i < x; i++)
		result *= 2;
	return result;
}