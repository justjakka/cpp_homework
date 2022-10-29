#include <stdlib.h>
#include <math.h>
#include <stdio.h>


float* get_geometric_progression(float a, float r, int n)
{
    float* res = (float*)malloc(sizeof(float) * n);
    for (int i = 0; i < n; i++)
    {
        res[i] = a * pow(r, i);
    }
    return res;
}


int main()
{
    float* threes = get_geometric_progression(1.0, 3.0, 10);
    for (int i = 0; i < 10; i++)
        printf("%.f\n", threes[i]);
}