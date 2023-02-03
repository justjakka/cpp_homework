#include <stdio.h>
#include <limits.h>

int pow_two(int p)
{
    int result = 1;
    for (int i = 0; i < p; i++)
        result *= 2;
    return result;
}


void process_binary(int num, int a[])
{
    if (num == 0)
        return;
    else {
        for (int i = 0; i <= 31; i++) {
            if (num - pow_two(31 - i) >= 0) {
                a[i] = 1;
                process_binary(num - pow_two(31 - i), a);
                break;
            }
        }
    }
}


void print_binary(int num)
{   
    if (num == 0)
        printf("%i\n", 0);
    else {
        int a[32];
        for (int i = 0; i < 32; i++)
            a[i] = 0;
        process_binary(num, a);

        int flag = 0;

        for (int i = 0; i < 32; i++) {
            if (a[i] == 0) {
                if (flag)
                    printf("%i", 0);
            }
            else {
                flag = 1;
                printf("%i", 1);
            }
        }
        printf("\n");
    }
    
}


int main()
{
    int num;
    scanf("%i", &num);
    print_binary(num);
}