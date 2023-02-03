#include <stdio.h>
#include <math.h>


double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double length(double x, double y) {
    return distance(x, y, 0, 0);
}

double scalar_product(double x1, double y1, double x2, double y2) {
    return x1 * x2 + y1 * y2;
}

double to_degrees(double rad) {
    return rad * 180 / M_PI;
}


int main()
{
    int x_1, x_2, y_1, y_2;
    scanf("%i %i %i %i", &x_1, &y_1, &x_2, &y_2);
    double len = length(x_1, y_1);
    len *= length(x_2, y_2);
    double scalar = scalar_product(x_1, y_1, x_2, y_2);
    double result = scalar / len;
    if (result)
        printf("%lf\n", to_degrees(acos(result)));
    else
        printf("%i\n", 90);
}