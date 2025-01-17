#include <stdio.h>

/*
Count characters in an input until EOF
*/
void main()
{
    int c, count=0;
    while ((c = getchar()) != EOF && c != 10)
    {
        count++;
    }
    printf("Character Count = %d\n", count);
}