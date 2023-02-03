#include <stdio.h>
#include <math.h>


double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    int x1, y1, r1, x2, y2, r2;
    scanf("%i %i %i %i %i %i", &x1, &y1, &r1, &x2, &y2, &r2);
    double len = distance(x1, y1, x2, y2);
    if ((r1 + r2) < len)
        printf("Do not intersect\n");
    else if ((r1 + r2) == len)
        printf("Touch\n");
    else
        printf("Intersect\n");
}