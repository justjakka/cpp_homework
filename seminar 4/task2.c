#include <stdio.h>


unsigned long long fact(int n, int k)
{
    unsigned long long result = 1;
    for (k; k <= n; ++k){
        result *= k;
    }
    return result;
}

int main()
{
    int n, k;
    scanf("%i %i", &n, &k);
    printf("%llu\n", fact(n, n - k + 1));
}