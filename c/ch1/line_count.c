#include <stdio.h>

void main()
{
    int c, lc = 0;
    while ((c = getchar()) != 'q' )
        if (c == '\n')
            ++lc;
    
    printf("%d\n", lc);
}