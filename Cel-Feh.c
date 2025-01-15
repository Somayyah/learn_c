#include <stdio.h>
/*
C Programming language by Brian W. Kernighan & Dennis M. Ritchie

Section 1.2
*/

/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 
*/

#define UPPER 300
#define LOWER 0
#define STEP 20

void main()
{
    for (float fahr = LOWER ; fahr <= UPPER ; fahr = fahr + STEP)
        printf("%3.1f %6.1f\n", fahr , (5.0/9.0) * (fahr-32) );

}