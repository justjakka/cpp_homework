#include <stdio.h>

void alice(int);
void bob(int);


void alice(int n)
{
    n *= 3;
    n++;
    printf("Alice: %i\n", n);
    bob(n);
}


void bob(int n)
{
    if (n != 1) {
        while (!(n % 2)) {
            n /= 2;
            printf("Bob: %i\n", n);
        }
        if (n != 1)
            alice(n);
        }
}


int main()
{
    int num;
    scanf("%i", &num);
    alice(num);
}