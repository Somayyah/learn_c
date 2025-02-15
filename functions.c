#include <stdio.h>

double power(int i, int j);

int main()
{

    for (int i = -5; i < 10; ++i)
        printf("%d %0.5lf %0.5lf\n", i, power(2,i), power(-3,i));
    return 0;
}

double power(int i, int j)
{
    if (i == 0 && j < 0) return 0; //  Undefined treated as 0
    if (j == 0) return 1; // By convention

    double res = 1.0;

    int abs_exp = ( j > 0) ? j : -j;
    
    for ( ; abs_exp > 0 ; abs_exp--)
        res = res * i;

    if (j < 0) return 1.0 / res;
    return res;
}