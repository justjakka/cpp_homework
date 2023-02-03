#include <stdio.h>


float yearfrac(int year, int day)
{
    if (year % 4)
        return day / 365.0;
    else
        return day / 366.0;
}

int main()
{
    int year, day;
    scanf("%i %i", &year, &day);
    printf("%.5f\n", yearfrac(year, day));
}