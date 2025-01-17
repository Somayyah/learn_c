#include <stdio.h>

/* count characters in input */

void main()
{
    double nc;
    for (nc = 0; getchar() != EOF; ++nc)
    ;
    printf("%.0f\n", nc);
}

// Next: 1.5.3 Line Counting