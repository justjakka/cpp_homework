#include <stdio.h>
#define MAX 3


void assign(int A[MAX][MAX], int B[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = B[i][j];
        }
    }
}

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

void power(int A[MAX][MAX], int C[MAX][MAX], int n, int k)
{
    int B[MAX][MAX];
    assign(B, A, MAX);
    if (k > 1){
        for (int i = 1; i < k; i++) {
            multiply(A, B, C, MAX);
            assign(B, C, MAX);
        }
    }
    
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j)
            printf("%i ", B[i][j]);
        printf("\n");
    }
}


int main()
{
    int a[MAX][MAX];
    int c[MAX][MAX];
    int k;
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            scanf("%i", &a[i][j]);   
        }
    }
    scanf("%i", &k);
    power(a, c, MAX, k);
}