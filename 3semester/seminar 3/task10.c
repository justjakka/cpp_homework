#include <stdio.h>


void last_digits(int a[], int size)
{
    for (int i = 0; i < size; i++)
        a[i] %= 10;
}


int main()
{
    int a[5] = {12314, 2352345, 3345, 453453, 5324};
    last_digits(a, 5);
    
    for (int i = 0; i < 5; ++i)
        printf("%i ", a[i]);
    printf("\n");
}