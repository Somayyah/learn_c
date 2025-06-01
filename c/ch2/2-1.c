/*
Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, 
by printing appropriate values from standard headers and by direct computation. Harder if you compute them: 
determine the ranges of the various floating-point types.
*/

#include <limits.h>
#include <stdio.h>

int main()
{
	printf("Ranges according to standard headers:");
	for(int i = 0; i >= 64 ; i++)
		printf("i : %d", i);
	printf("Ranges calculated:");
	for(int i = 0; i >= 64 ; i++)
		printf("i : %d", i);
	return 0;
}