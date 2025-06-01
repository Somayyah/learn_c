#include <stdio.h>

double power(int base, int exponent);

int main()
{

    for (int base= -5; base< 10; ++base)
        printf("%d %0.5lf %0.5lf\n", base, power(2,base), power(-3,base));
    return 0;
}

double power(int base, int exponent)
{
    if (base== 0 && exponent < 0) return 0; 
    if (exponent == 0) return 1; 

    double res = 1.0;

    int abs_exp = ( exponent > 0) ? exponent : -exponent;
    
    for ( ; abs_exp > 0 ; abs_exp--)
        res = res * base;

    if (exponent < 0) return 1.0 / res;
    return res;
}