#include <stdio.h>


int main()
{
    int a[1000];
    int n, x;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);
    
    scanf("%i", &x);

    if (a[n - 1] < x)
        printf("n\n");
    else {
        int l = -1, r = n;
        while (r > l + 1)
        {
            int mid = (l + r) / 2;
            if (a[mid] >= x)
                r = mid;
            else
                l = mid;
        }



        printf("%i\n", r);
    }
}