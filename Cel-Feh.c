#include <stdio.h>
/*
C Programming language by Brian W. Kernighan & Dennis M. Ritchie

Section 1.2
*/

/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 
*/

void main()
{
    // Define variables for Fehrinheit, lower and upper
    float f = 0;
    float c = 0;
    while(f <= 300)
    {
        c = (5.0/9.0) * (f-32.0) ;
        printf("%3.0f %6.1f\n", f, c);
        f = f + 20;
    }
}