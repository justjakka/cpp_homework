#include <stdio.h>


int sum_of_digits(int num)
{
    int temp = 0;
    while (num != 0) {
        temp += num % 10;
        num /= 10;
    }
    return temp;
}


int sum_of_digits_rec(int num)
{
    if (num == 0)
        return 0;
    else {
        int temp = num % 10;
        temp += sum_of_digits_rec(num / 10);
        return temp;
    }
}


int main()
{
    int num;
    scanf("%i", &num);

    printf("%i\n", sum_of_digits(num));
    printf("%i\n", sum_of_digits_rec(num));
}