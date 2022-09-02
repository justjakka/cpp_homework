#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%i", &n);
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        int a;
        scanf("%i", &a);
        if (a < min && !(a % 2))
            min = a;
        else if (a > max && (a % 2))
            max = a;
    }
    
    if (min == INT_MAX)
        printf("None ");
    else
        printf("%i ", min);
    
    if (max == INT_MIN)
        printf("None\n");
    else
        printf("%i\n", max);
    
}