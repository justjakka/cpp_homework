#include <stdio.h>


int main()
{
    int a[1000][1000];
    int n, m, x, temp;
    scanf("%i", &n);
    scanf("%i", &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%i", &a[i][j]);   
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n - 1 - i; ++k) {
                if (a[k][j] > a[k + 1][j]) {
                    int temp = a[k][j];
                    a[k][j] = a[k + 1][j];
                    a[k + 1][j] = temp;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }
}