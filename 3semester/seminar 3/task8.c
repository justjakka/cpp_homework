#include <stdio.h>


int count_even(int array[], int size)
{
    int temp = 0;
    for (int i = 0; i < size; i++) {
        if (!(array[i] % 2))
            temp++; 
    }
    return temp;
}


int main()
{
    int a[5] = {10, 20, 30, 40};
    printf("%i\n", count_even(a, 4));
}