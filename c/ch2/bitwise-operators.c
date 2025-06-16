#include <stdio.h>

int main()
{
    char x = 7, y = 4;
    printf("Result of x&y : %d\n", x&y);
    printf("Result of x&&y : %d\n", x&&y);
    printf("Result of x << y : %d\n", x << y); // Must give 7 * 2^(4)
    printf("Result of x >> y : %d\n", x >> y);
    return 0;
}
