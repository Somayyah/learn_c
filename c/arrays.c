/********************************************************************
* write a program to count the number of occurrences of each digit, * 
* of white space characters (blank, tab, newline), and of all other *
* characters. This is artificial, but it permits us to illustrate   *
* several aspects of C in one program.                              *
 *******************************************************************/ 

// Trying the book's solution 

#include <stdio.h>

int main()
{   
    int c, cn, bn ; // Characters, Blanks, Newlines, Tabs
    int ndigits[10];        // Number of occurrences of each digit

    for (int i = 0; i < 10; i++) {
        ndigits[i] = 0;
    } 
    cn = bn = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t') 
            { 
                ++bn;
                continue;
            }
        if (c >= '0' && c <= '9')
        {
            ++ndigits[c - '0']; // Increment the count for the specific digit
            continue;
        }
        ++cn;
    } 

    // Print counts
    printf("Characters: %d\n", cn);
    printf("Blanks: %d\n", bn);
    
    printf("Digits count:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: %d\n", i, ndigits[i]);
    }

    return 0;
}