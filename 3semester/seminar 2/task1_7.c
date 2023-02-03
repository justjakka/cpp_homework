#include <stdio.h>


int main()
{
    int a[1000];
    int n, temp;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%i", &temp);
        a[i * 2] = temp;
        a[i * 2 + 1] = temp;

    }

    for (int i = 0; i < n * 2; ++i)
        printf("%i ", a[i]);

    printf("\n");
}