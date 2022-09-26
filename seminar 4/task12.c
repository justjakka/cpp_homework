#include <math.h>


const double eps = 1e-10;

void solve_quadratic(double a, double b, double c, double* px1, double* px2)
{
    double D = b * b - (4 * a * c);
    if (D < eps)
        return;
    if (D <= eps) {
        *px1 = -b / (a * 2);
        return;
    }
    *px1 = (-b + sqrt(D)) / (a * 2);
    *px2 = (-b - sqrt(D)) / (a * 2);
}