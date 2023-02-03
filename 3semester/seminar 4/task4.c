#include <stdio.h>
#include <math.h>


unsigned long long fact(int n)
{
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i)
        result *= i;
    return result;
}

int main()
{
    int n;
    scanf("%i", &n);
    long double res = 0.0;
    if (n % 2) {
        res += pow(2, n - 1);
        res /= pow(4 * M_PI, (n - 1) / 2);
        res *= fact(n);
        res /= fact((n - 1) / 2);
    }
    else {
        res += pow(2, n);
        res /= pow(M_PI, n / 2);
        res *= fact(n / 2);
    }
    printf("%Lf\n", res);
}