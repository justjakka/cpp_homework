#include <stdio.h>


int main()
{
    int a[1000];
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    int index;
    scanf("%i", &index);

    for (int i = index; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    for (int i = 0; i < n - 1; ++i)
        printf("%i ", a[i]);

    printf("\n");
}