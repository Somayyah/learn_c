#include <stdio.h>

/* count characters in input */

void main()
{
    int nc;
    for (nc = 0; getchar() != EOF; ++nc)
    ;
    printf("%.0f\n", nc);
}