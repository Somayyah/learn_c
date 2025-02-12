/*
    Exercise 1-14. Write a program to print a histogram of the frequencies 
    of different characters in its input.
*/
#include <stdio.h>

#define REPEAT(___, _) for(char *__ = ___; *__; __++) putchar(_)

int main()
{
    int c = 0 ; 
    int chars[95] = {0}; // array to hold ascii characters from ' ' to '~'

    while ((c = getchar()) != EOF)
    {
        if (c >= ' ' && c <= '~') ++chars[c-' '];
    }

    printf("\nC : F\n");
    for (int i = 32; i < 127; i++)
    {
        if ( chars[i - ' '] > 0)
        {
            printf("%c : ", i);
            for (int j = 0; j < chars[i-' ']; j++) putchar('*');
            putchar('\n');
        }
    }
    return 0;
}