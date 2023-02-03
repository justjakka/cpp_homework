#include <stdio.h>


int main()
{
    int a[1000];
    int n, x;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    int left = 0, right = n - 1;
    while (right > left + 1)
    {
        int mid1 = (left + (right - left + 1) / 3);
        int mid2 = (left + (2 * (right - left) - 1) / 3);
        if (a[mid1] == a[mid2] && mid1 != mid2)
        {
            right = mid2;
            left = mid1;
        }
        else if (mid1 == mid2)
        {
            mid2 = right - 1;
            mid1 = left + 1;
        }
        if (a[mid1] > a[mid2])
            right = mid2;
        else
            left = mid1;
    }
    if (a[right] >= a[left])
    printf("%i\n", right);
    else
    printf("%i\n", left);
}