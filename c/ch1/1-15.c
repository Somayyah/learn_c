/*
Exercise 1.15. Rewrite the temperature conversion 
program of Section 1.2 to use a function for conversion.
*/

#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

double temp_in_cel(double fahr)
{
    return (5.0/9.0) * (fahr-32);
}

int main()
{
    for (float fahr = LOWER ; fahr <= UPPER ; fahr = fahr + STEP)
        printf("%3.3f %6.3f\n", fahr , temp_in_cel(fahr));
}
