#include <stdio.h>

#define MAX 10


void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }   
        }
    }
}


int main()
{
    int a[MAX][MAX];
    int b[MAX][MAX];
    int c[MAX][MAX];

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            scanf("%i", &a[i][j]);   
        }
    }
    
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            scanf("%i", &b[i][j]);   
        }
    }

    multiply(a, b, c, MAX);

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j)
            printf("%i ", c[i][j]);
        printf("\n");
    }
    printf("\n");
}