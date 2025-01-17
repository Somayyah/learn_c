#include <stdio.h>

/*
read a character
while (charater is not end-of-file indicator)
output the character just read
read a character
*/
void main()
{
    int c = ' ';
    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
    printf("Bye\n");
}