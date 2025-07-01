#include <stdio.h>

int main()
{
	
	return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
	if (((p+1-n) < 0) || n <= 0 || p < 0 )
		return -1 ; // Invalid
	
	return ( (x >> (p+1-n) ) & (~(~0 << n)) );
}