#include <stdio.h>


int main()
{
    int a[1000];
    int n, m, x, temp;
    scanf("%i", &n);
    scanf("%i", &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0)
                scanf("%i", &a[j]);
            else {
                scanf("%i", &temp);
                a[j] += temp;
            }
                
        }
    }

    for (int i = 0; i < m; ++i)
        printf("%i ", a[i]);

    printf("\n");
}