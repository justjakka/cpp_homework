#include <stdio.h>


void triangle(int num)
{
    for (int i = 1; i <= num; i++) {
        for (int j = 0; j < i; j++)
            printf("*");
        printf("\n");
    }
}


int main()
{
    int n;
    scanf("%i", &n);
    triangle(n);
}