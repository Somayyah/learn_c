/*
Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, 
by printing appropriate values from standard headers and by direct computation. Harder if you compute them: 
determine the ranges of the various floating-point types.
*/

#include <limits.h>
#include <stdio.h>

int to_power_int(int x);
long to_power_long(int x);
unsigned int to_power_int_unsigned(int x);
unsigned long to_power_long_unsigned(int x);


int main()
{
	printf("=================== Via limits.h ===================\n\n");

	printf("Minimum value of signed\n\n");

	printf("Char : %d\n", SCHAR_MIN);
	printf("Short : %d\n", SHRT_MIN);
	printf("Int : %d\n", INT_MIN);
	printf("Long : %ld\n\n", LONG_MIN);

	printf("Maximum value of signed\n\n");

	printf("Char : %d\n", SCHAR_MAX);
	printf("Short : %d\n", SHRT_MAX);
	printf("Int : %d\n" , INT_MAX);
	printf("Long : %ld\n\n", LONG_MAX);

	printf("Maximum value of unsigned\n\n");

	printf("Char : %u\n", UCHAR_MAX);
	printf("Short : %u\n", USHRT_MAX);
	printf("Int : %u\n" , UINT_MAX);
	printf("Long : %lu\n\n", ULONG_MAX);
  

	printf("================ Ranges calculated ================\n\n");
	
	printf("Signed:\n\n");

	printf("%s : Min = %d, Max = %d\n", "Char" , -1 * to_power_int( 8 * (sizeof(char) ) - 1) , to_power_int( 8 * (sizeof(char) ) - 1) - 1);
	printf("%s : Min = %d, Max = %d\n", "Short" , -1 * to_power_int( 8 * (sizeof(short) ) - 1) , to_power_int( 8 * (sizeof(short) ) - 1) - 1);
	printf("%s : Min = %d, Max = %d\n", "Int" , -1 * to_power_int( 8 * (sizeof(int) ) - 1) , to_power_int( 8 * (sizeof(int) ) - 1) - 1);
	printf("%s : Min = %ld, Max = %ld\n", "Long" , -1 * to_power_long( 8 * (sizeof(long) ) - 1) , to_power_long( 8 * (sizeof(long) ) - 1) - 1);
	
	printf("\nUnsigned:\n\n");

	printf("%s : Min = 0, Max = %u\n", "Char" , to_power_int_unsigned( 8 * (sizeof(unsigned char) )) - 1);
	printf("%s : Min = 0, Max = %u\n", "Short" , to_power_int_unsigned( 8 * (sizeof(unsigned short) )) - 1);
	printf("%s : Min = 0, Max = %u\n", "Int" , to_power_int_unsigned( 8 * (sizeof(unsigned int) )) - 1);
	printf("%s : Min = 0, Max = %lu\n", "Long" , to_power_long_unsigned( 8 * (sizeof(unsigned long) )) - 1);

	return 0;
}

int	to_power_int(int x)
{
	int result = 1;
	for (int i = 0; i < x; i++)
		result *= 2;
	return result;
}

long to_power_long(int x)
{
	long result = 1L;
	for (long i = 0; i < x; i++)
		result *= 2;
	return result;

}

unsigned int to_power_int_unsigned(int x)
{
	unsigned int result = 1;
	for (int i = 0; i < x; i++)
		result *= 2;
	return result;
}

unsigned long to_power_long_unsigned(int x)
{
	unsigned long result = 1UL;
	for (long i = 0; i < x; i++)
		result *= 2;
	return result;
}