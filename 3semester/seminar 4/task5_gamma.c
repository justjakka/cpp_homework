#include <stdio.h>
#include <math.h>


double gamma(double x)
{
    const double step = 1e-2;
    const double eps = 1e-10;
    double t = 0;
    double temp;
    double area = 0;
    temp = pow(t + step, x-1) * pow(M_E, -t);
    while (temp * (1 / 2.0) * step <= eps){
        t += step;
        temp = pow(t + step, x - 1) * pow(M_E, -t);
    }
    while (temp * (1 / 2.0) * step > eps)
    {
        area += (temp + pow(t, x - 1) * pow(M_E, -t)) * step * 0.5;
     
        t += step;
        temp = pow(t + step, x - 1) * pow(M_E, -t - step);
    }
    return area;
}

int main()
{
    double x;
    scanf("%lf", &x);
    printf("%.5E", gamma(x));
}
