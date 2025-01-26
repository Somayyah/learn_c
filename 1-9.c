/****************************************************************
 * Exercise 1-9: Write a program to copy its input to its       *
 * output, replacing each string of one or more blanks by a     *
 * single blank.                                                *
 *                                                              *
 * Description:                                                 *
 * This program processes input text and compresses multiple    *
 * consecutive blank spaces into a single blank space.          *
 *                                                              *
 * Example:                                                     *
 * Input: "Hello     world!   How are   you?"                   *
 * Output: "Hello world! How are you?"                          *
 ***************************************************************/

#include <stdio.h>
// #include <stdbool.h>

int main()
{
    int c = ' ';
    while ((c = getchar()) != EOF )
    {
        printf("Char Before: %c\n", c);
        if ( c == ' ') { 
            if (c == (c = getchar())) continue;
            //putchar(c);
            printf("Char In loop: %c\n", c);
        }
        printf("Char after: %c\n", c);
        //putchar(c);
    }
    //printf("%d", putchar(' '));
        
    return 0;
}