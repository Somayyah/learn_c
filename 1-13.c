/********************************************************************
* Exercise 1-13. Write a program to print a histogram of the lengths*
* of words in its input. It is easy to draw the histogram with the  *
* bars horizontal; a vertical orientation is more challenging.      *
*********************************************************************/

#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c, histogram[10], counter, STATE; // String, histogram array, letters counter, in / outside a word
    c = counter = 0;

    for (int i = 0; i < 10; i++)
    {
        histogram[i] = 0;
    }
    
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t') 
        {
            STATE = OUT;
            continue;
        }


    }

    return 0;
}

