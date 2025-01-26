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
        if ( c == ' ') { 
            if (c == (c = getchar())) continue;
            putchar(c);
        }
        putchar(c);
    }
        
    return 0;
}