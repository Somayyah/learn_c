/*
	Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table.
*/

#include <stdio.h>

int main()
{
	float fahr, celsius;
	float lower, upper, step;
	lower = 0; /* lower limit of temperatuire scale */
	upper = 400; /* upper limit */
	step = 20; /* step size */
	celsius = lower;
	printf("Cel  Fahr\n---  -----\n");
	while (celsius <= upper) {
		fahr = celsius * (9.0 / 5.0) + 32;
		printf("%3.0f  %3.1f\n",celsius, fahr);
		celsius = celsius + step;
	}
	
	printf("%f\n", (9/5));
}