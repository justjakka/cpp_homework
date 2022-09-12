#include <stdio.h>


int main()
{
    int a[1000];
    int n;
    int counter = 0;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    for (int i = 0; i < n; i++) {
        if (a[i] < 0)
            counter++;
        else
            a[i - counter] = a[i];
    }

    for (int i = 0; i < n - counter; ++i)
        printf("%i ", a[i]);

    printf("\n");
}