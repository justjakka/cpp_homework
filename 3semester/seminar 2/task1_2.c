#include <stdio.h>


int main()
{
    int a[1000];
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    int new_elem, index;
    scanf("%i", &new_elem);
    scanf("%i", &index);

    for (int i = n - 1; i > index; i--) {
        a[i + 1] = a[i];
    }

    a[index + 1] = new_elem;

    for (int i = 0; i < n + 1; ++i)
        printf("%i ", a[i]);

    printf("\n");
}