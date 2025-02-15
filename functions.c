#include <stdio.h>

double power(int i, int j);

int main()
{
    double i;
    for (i = -5; i < 10; ++i)
        printf("%0.2f %0.2lf %0.2lf\n", i, power(2,i), power(-3,i));
    return 0;
}

double power(int i, int j)
{
    if (j == 0) return 1;
    long int res = i;
    if (j < 0)
    {
        for (j ; j < 1; j++)
            res = res * i;
        return 1 / res;
    }
    for (j ; j > 1 ; j--)
        res = res * i;
    return res;
}