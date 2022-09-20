#include <stdio.h>


void dec(int a[], int size)
{
    for (int i = 0; i < size; i++)
        a[i]--;
}


int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    dec(a, 5);
    
    for (int i = 0; i < 5; ++i)
        printf("%i ", a[i]);
    printf("\n");
}