#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    // Integer types
    printf("Integer Types:\n");
    printf("Size of char: %zu bytes, Min: %d, Max: %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("Size of short: %zu bytes, Min: %d, Max: %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("Size of int: %zu bytes, Min: %d, Max: %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("Size of long: %zu bytes, Min: %ld, Max: %ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("Size of long long: %zu bytes, Min: %lld, Max: %lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
    
    // Unsigned integer types
    printf("\nUnsigned Integer Types:\n");
    printf("Size of unsigned char: %zu bytes, Min: 0, Max: %u\n", sizeof(unsigned char), UCHAR_MAX);
    printf("Size of unsigned short: %zu bytes, Min: 0, Max: %u\n", sizeof(unsigned short), USHRT_MAX);
    printf("Size of unsigned int: %zu bytes, Min: 0, Max: %u\n", sizeof(unsigned int), UINT_MAX);
    printf("Size of unsigned long: %zu bytes, Min: 0, Max: %lu\n", sizeof(unsigned long), ULONG_MAX);
    printf("Size of unsigned long long: %zu bytes, Min: 0, Max: %llu\n", sizeof(unsigned long long), ULLONG_MAX);
    
    // Floating-point types
    printf("\nFloating-point Types:\n");
    printf("Size of float: %zu bytes, Min: %e, Max: %e\n", sizeof(float), FLT_MIN, FLT_MAX);
    printf("Size of double: %zu bytes, Min: %e, Max: %e\n", sizeof(double), DBL_MIN, DBL_MAX);
    printf("Size of long double: %zu bytes, Min: %Le, Max: %Le\n", sizeof(long double), LDBL_MIN, LDBL_MAX);

    return 0;
}
