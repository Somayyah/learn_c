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
        if ((c == ' ' || c == '\n' || c == '\t') && STATE == IN) // Check if we are outside  
        {
            STATE = OUT;
            counter = 0;
            continue;
        }

        while ((c = getchar()) != '\n' && c != ' ' && c != '\t' ) // Check if we are in
        {
            if (c == EOF)
                break;
            ++counter; // letter counter incremented
            STATE = IN;
        }
        ++histogram[counter];
        counter = 0;
    }

    for (int i = 0; i < 10 ; i++)
        printf("%d : %d\n", i, histogram[i]);
    return 0;
}

