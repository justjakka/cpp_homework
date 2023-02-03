#include <stdio.h>


const double eps = 1e-10;

double f(double x)
{
    double f;
    f = x * x - 7;
    return f;
}

int main()
{
    double l = 0;
    double h = 7;
    while(h - l > eps)
    {
        if (f((l + h) / 2) >= 0)
            h = (l + h) / 2;
        else
            l = (l + h) / 2;
    }
    printf("%lf\n", (l + h) / 2);
}