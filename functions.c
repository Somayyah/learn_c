#include <stdio.h>

long int power(int i, int j)
{
    long int res = i;
    for (j ; j > 1 ; j--)
        res = res * i;
    return res;
}

int main()
{
    printf("%ld\n", power(2,32));
    return 0;
}