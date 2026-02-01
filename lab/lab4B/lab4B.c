#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
long long XOR(long long a, long long b) {
    return ~(a & b) & ~(~a & ~b);
}

int main() 
{
    long long n;
    scanf("%lld", &n);
    long long result = 0;
    while (n > 0) 
    {
        result = XOR(result, n);
        n = n >> 1;
    }
    printf("%lld\n", result); 
    return 0;
}