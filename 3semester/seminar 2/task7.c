#include <stdio.h>


int sum(int num) 
{
    int sum = 0;
    while (!(num == 0)) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}


int main()
{
    int a[10000];

    for (int i = 0; i < 10000; ++i) {
        scanf("%i", &a[i]);   
    }

    for (int j = 0; j < 10000; ++j)
    {
        for (int i = 0; i < 10000 - 1 - j; ++i)
        {
            if (sum(a[i]) > sum(a[i + 1]))
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 10000; ++i) {
        printf("%i ", a[i]);
    }
    printf("\n");
}