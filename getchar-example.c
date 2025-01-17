#include <stdio.h>

/*
read a character
while (charater is not end-of-file indicator)
output the character just read
read a character
*/
void main()
{
    int c; // testing int with EOF
    while ((c = getchar()) != EOF)
    {
        printf("c (char value) = %c\tc (int value) = %d\n", c, c);
        //putchar(c);
    }
    printf("Bye\n");
}