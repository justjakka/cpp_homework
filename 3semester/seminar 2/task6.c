/* компилятор выбрасывает ошибку если двумерные массивы ставить по 1000 */

#include <stdio.h>


int main()
{
    int a[100][100];
    int b[100][100];
    int res[100][100];
    int n;

    scanf("%i", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%i", &a[i][j]);   
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%i", &b[i][j]);   
        }
    }

    printf("\n");

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                res[i][j] += a[i][k] * b[k][j];
            }   
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%i ", res[i][j]);
        printf("\n");
    }
    printf("\n");
}