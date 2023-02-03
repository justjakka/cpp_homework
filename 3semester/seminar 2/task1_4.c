#include <stdio.h>


int main()
{
    int a[1000];
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    int start_index, end_index;
    scanf("%i", &start_index);
    scanf("%i", &end_index);

    for (int i = start_index; i < end_index; i++) {
        a[i] = a[i + end_index - start_index];
    }

    for (int i = 0; i < n - end_index + start_index; ++i)
        printf("%i ", a[i]);

    printf("\n");
}