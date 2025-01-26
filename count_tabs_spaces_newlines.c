// Exercise 1-8. Write a program to count blanks, tabs, and newlines.

#include <stdio.h>

void main()
{
    int c, blanks = 0, tabs = 0, nl = 0;

    while ((c = getchar()) != EOF){
        if (c == ' ') 
            ++blanks;
        else if (c == '\t')
            ++tabs;
        else if (c == '\n')
            ++nl;
    }
    
    printf("Blanks: %d\nTabs: %d\nNewLines: %d\n", blanks, tabs, nl);
}