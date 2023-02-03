#include <stdio.h>


int main(){
    int n;
    int length = 1;
    scanf("%i", &n);
    int max = n;
    printf("%i", n);
    while (!(n == 1)){
        ++length;
        if (!(n % 2)){
            n /= 2;
            if (n > max)
                max = n;
            printf(" %i", n);
        }
        else {
            n = 3 * n + 1;
            if (n > max)
                max = n;
            printf(" %i", n);
        }
    }

    printf("\nLength = %i, Max = %i\n", length, max);
}