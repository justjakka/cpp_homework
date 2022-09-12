#include <stdio.h>


int main()
{
    int a[1000];
    int n, x;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    int flag = 1;
    for (int i = 0; i < n; ++i) {
        if (!(i == 0)) {
            if (a[i] < a[i - 1]) {
                printf("%i\n", i - 1);
                flag = 0;
                break;
            }
        }

    }
    if (flag)
        printf("%i\n", n - 1);
}