/*
	Exercise 1-5. Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.
*/

#include <stdio.h>

int main()
{
	float fahr, celsius;
	float lower, upper, step;
	lower = 0; /* lower limit of temperatuire scale */
	upper = 300; /* upper limit */
	step = 20; /* step size */
	celsius = upper;
	printf("Cel  Fahr\n---  -----\n");
	while (celsius >= lower) {
		fahr = celsius * (9.0 / 5.0) + 32;
		printf("%3.0f  %3.1f\n",celsius, fahr);
		celsius = celsius - step;
	}
	return 0;
}