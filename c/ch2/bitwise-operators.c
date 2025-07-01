#include <stdio.h>

int main()
{
    unsigned x = 7, y = 4;
    printf("Result of x&y : %d\n", x&y);
    printf("Result of x&&y : %d\n", x&&y);
    printf("Result of x << y : %d\n", x << y); // Must give 7 * 2^(4)
    printf("Result of x >> y : %d\n", x >> y); // Must give 7 / 2^(4)
	
	printf("\nCreate a mask for Kth bit set : 1 << (k-1)\n\n");
	printf("Find if a number is odd  or even : n & 1\nOdd ==> 1\nEven ==> 0\n\n");
	printf("Kth bit is set? (1 == yes, 0 == no): (n & (1 << (k-1))) != 0\n\n");

	printf("Number of combinations of a subset : 0 to (1 << n) - 1\nfor (int mask = 0; mask < (1 << n); mask++) {\n...\n\n}");
	printf("Shift n bits at position p to the right:     x >> (p + 1 - n)\n");
	printf("Create a mask of rightmost n bits:           ~(~0U << n)\n");
	printf("Extract rightmost n bits from x:             x & ~(~0U << n)\n");
	
    return 0;
}
