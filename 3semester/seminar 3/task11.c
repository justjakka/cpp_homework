#include <stdio.h>


void reverse(int array[], int size)
{
    for (int i = 0; i < size / 2; ++i) {
        int temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}


int main()
{
    int a[6] = {10, 20, 30, 40, 50, 60};

    reverse(a, 6);

    for (int i = 0; i < 6; i++) {
        printf("%i ", a[i]);
    }
    printf("\n");
}