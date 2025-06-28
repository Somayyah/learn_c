#include <stdio.h>

int main()
{
    char x = 7, y = 4;
    printf("Result of x&y : %d\n", x&y);
    printf("Result of x&&y : %d\n", x&&y);
    printf("Result of x << y : %d\n", x << y); // Must give 7 * 2^(4)
    printf("Result of x >> y : %d\n", x >> y); // Must give 7 / 2^(4)
	
	printf("\nCreate a mask for Kth bits : 1 << (k-1)\n\n");
	printf("Find if a number is odd  or even : n & 1\nOdd ==> 1\nEven ==> 0\n\n");
	
    return 0;
}
