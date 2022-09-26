#include <stdio.h>


int main()
{
    long double result = 0.0;
    int n;
    scanf("%i", &n);
    int flag = 0;
    long double one = 1.0;
    for (int i = 1; i <= n; ++i) {
        if (flag) {
            result -= one / (2 * i - 1);
            flag = 0;
        }
        else {
            result += one / (2 * i - 1);
            flag = 1;
        }
    }
    printf("%Lf\n", result * 4);
}