#include <stdio.h>


int trib_process(int num, int a[])
{
    if (num == 1 || num == 0)
        return 0;
    else if (num == 2)
        return 1;
    else {
        if (!a[num])
            a[num] = trib_process(num - 3, a) + trib_process(num - 2, a) + trib_process(num - 1, a);
        return a[num];
    }
}


int trib(int num) 
{
    int a[1000] = {0, 0, 1};
    return trib_process(num, a);
}


int main()
{
    int num;
    scanf("%i", &num);
    printf("%i\n", trib(num));
}