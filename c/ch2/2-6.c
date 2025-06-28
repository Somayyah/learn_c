/*
Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.

x = 0000 1111
p = 3
n = 5
y = 1101 1010
*/
#include <stdio.h>

unsigned setbits(unsigned x,int p,int n,unsigned y);

int main()
{
	unsigned int x = 100;
	unsigned int y = 100;
	int p = 0, n = 0;
	
	printf("%u\n", setbits(x,p,n, y) );
	
	return 0;
}

unsigned setbits(unsigned x,int p,int n,unsigned y)
{
	unsigned mask = ~(~0 << n);  
	y = y & mask;
	
	return x; 
}