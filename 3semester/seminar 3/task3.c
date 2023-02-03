#include <stdio.h>


void print_even(int a, int b)
{   
    int temp = a;
    if (a % 2)
        temp = a + 1;
    for (int i = 0; temp + 2 * i <= b; ++i) {
        printf("%i ", temp + 2 * i);
    }
    printf("\n");
}


int main()
{
    int a, b;
    scanf("%i", &a);
    scanf("%i", &b);

    print_even(a, b);
}