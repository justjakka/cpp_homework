#include <stdio.h>


int main()
{
    int a[1000];
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    for (int i = 0; i < n; ++i)
        a[n + i] = a[i];
    

    for (int i = 0; i < n * 2; ++i)
        printf("%i ", a[i]);

    printf("\n");
}