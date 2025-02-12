/*
    Exercise 1-14. Write a program to print a histogram of the frequencies 
    of different characters in its input.
*/
#include <stdio.h>
int main()
{
    int c = 0 ; 
    int chars[95] = {0}; // array to hold ascii characters from ' ' to '~'

    while ((c = getchar()) != EOF)
    {
        if (c <= ' ' && c <= '~') ++chars[c-' '];
    }

    printf("\nCharacter\tFrequency\n");
    for (int i = 32; i < 127; i++)
    {
        printf("%c\t%d\n", i, chars[i-' ']);
    }
    return 0;
}