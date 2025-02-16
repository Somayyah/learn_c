/****************************************************************
 * Exercise 1-12.                                               *
 * Write a program that prints its input, one word per line.    *
 ****************************************************************/ 

#include <stdio.h>

int main()
{
    int c = 0;
    while ((c = getchar()) != EOF) 
    {
        if (c == ' ' || c == '\n' || c == '\t') 
        {
            putchar('\n');
            while ((c = getchar()) == ' ' || c == '\n' || c == '\t');
        }
        if (c != EOF) putchar(c);
    }

    return 0;
}