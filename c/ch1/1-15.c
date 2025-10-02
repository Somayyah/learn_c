/*
	Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
*/

#include <stdio.h>

#define 	LOWER 	0
#define 	UPPER	300
#define		STEP 	20

int fahr_2_cel(int fahr);

int main()
{
	int fahr, celsius;
	int lower, upper, step;
	lower = LOWER; /* lower limit of temperature scale */
	upper = UPPER; /* upper limit */
	step = STEP; /* step size */
	fahr = lower;
	
	while (fahr <= upper) {
		celsius = fahr_2_cel(fahr);
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}

int fahr_2_cel(int fahr)
{
	return 5 * (fahr-32) / 9;
}