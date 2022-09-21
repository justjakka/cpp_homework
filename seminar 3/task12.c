#include <stdio.h>


void sort(int array[], int size)
{
    for (int j = 0; j < size; ++j)
    {
        for (int i = 0; i < size - 1 - j; ++i)
        {
            if (array[i] % 10 > array[i + 1] % 10)
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}



int main()
{
    int a[6] = {112312310, 21340, 3012, 454350, 503, 6120};

    sort(a, 6);

    for (int i = 0; i < 6; i++) {
        printf("%i ", a[i]);
    }
    printf("\n");
}