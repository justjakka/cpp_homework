#include <stdio.h>


void cube(float* p)
{
    float temp = *p;
    *p *= *p * temp;
}

int main()
{
    float n = 2.0;
    cube(&n);
    printf("%f\n", n);
}