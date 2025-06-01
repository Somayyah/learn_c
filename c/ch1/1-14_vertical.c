/*
    Exercise 1-14. Write a program to print a histogram of the frequencies 
    of different characters in its input.
*/
#include <stdio.h>

int main()
{
    int c = 0 ; 
    int chars[95] = {0}; // array to hold ascii characters from ' ' to '~'
    int isprinted = 0;
    while ((c = getchar()) != EOF)
    {
        if (c >= ' ' && c <= '~') ++chars[c-' '];
    }

    printf("\nC  : F\n");
    for (int i = 32; i < 127; i++)
    {
        if ( chars[i - ' '] > 0)
        {
            // will print histogram vertically
            isprinted = 1;
        }
    }

    if (isprinted == 0) printf("No printable ASCII characters (' ' to '~') found in input.\n");;
    return 0;
}