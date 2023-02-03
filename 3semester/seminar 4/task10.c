#include <stdio.h>


int main()
{
    int numbers[6] = {4, 8, 15, 16, 23, 42};
    int* p = &numbers[3];
    printf("numbers[5]\t\t\t\t%i\n", numbers[5]);
    printf("*p\t\t\t\t%i\n", *p);
    printf("*(p + 1)\t\t\t\t%i\n", *(p + 1));
    printf("*(p - 1)\t\t\t\t%i\n", *(p - 1));
    printf("p[0]\t\t\t\t%i\n", p[0]);
    printf("p[1]\t\t\t\t%i\n", p[1]);
    printf("p[-2]\t\t\t\t%i\n", p[-2]);
    printf("*numbers\t\t\t\t%i\n", *numbers);
    printf("*(numbers + 5)\t\t\t\t%i\n", *(numbers + 5));
    printf("p - numbers\t\t\t\t%i\n", p - numbers);
    printf("(short*)p - (short*)numbers\t\t\t\t%i\n", (short*)p - (short*)numbers);
    printf("(char*)p - (char*)numbers\t\t\t\t%i\n", (char*)p - (char*)numbers);
}