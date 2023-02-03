#include <stdio.h>


int main()
{
    int a[1000];
    int n, shift;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    scanf("%i", &shift);

    for (int i = n - 1; i >= 0; --i)
        a[i + shift] = a[i];
    
    
    for (int i = 0; i < shift; ++i)
        a[i] = a[n + i];


    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);

    printf("\n");
}