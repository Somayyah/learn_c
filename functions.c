#include <stdio.h>

double power(int i, int j);

int main()
{
    double i;
    for (i = -5; i < 10; ++i)
        printf("%0.0f %0.9lf %0.9lf\n", i, power(2,i), power(-3,i));
    return 0;
}

double power(int i, int j)
{
    if (j == 0) return 1;
    double res = 1;
    if (j < 0)
    {
        for (j ; j < 0; j++)
            res = res * i;
        return 1.0 / res;
    }
    for (j ; j > 0 ; j--)
        res = res * i;
    return res;
}