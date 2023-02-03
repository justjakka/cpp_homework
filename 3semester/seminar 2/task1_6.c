#include <stdio.h>


int main()
{
    int a[1000];
    int even[1000];
    int odd[1000];
    int n;
    int even_c = 0;
    int odd_c = 0;
    int counter = 0;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    for (int i = 0; i < n; i++) {
        if (a[i] % 2) {
            odd[odd_c] = a[i];
            odd_c++;
        }
        else {
            even[even_c] = a[i];
            even_c++;
        }
    }

    for (int i = 0; i < odd_c; ++i)
        printf("%i ", odd[i]);
    
    for (int i = 0; i < even_c; ++i)
        printf("%i ", even[i]);

    printf("\n");
}