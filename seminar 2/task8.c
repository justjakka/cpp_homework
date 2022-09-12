    /* программа рабочая, только как направить два файла одновременно я не знаю и найти
    как это сделать не смог (чисто редиректом, не внутренней функцией)*/
#include <stdio.h>


int main()
{
    int a[10][10];
    int b[10][10];
    int res[10][10];

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            scanf("%i", &a[i][j]);   
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            scanf("%i", &b[i][j]);   
        }
    }

    printf("\n");

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                res[i][j] += a[i][k] * b[k][j];
            }   
        }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j)
            printf("%i ", res[i][j]);
        printf("\n");
    }
    printf("\n");
}