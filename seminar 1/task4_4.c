#include <stdio.h>


int main(){
    int inc, dec, equal, temp, n;
    inc = dec = equal = 1;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
    {
        if (i == 0){
            int a;
            scanf("%i", &a);
            temp = a;
        }
        else {
            int a;
            scanf("%i", &a);
            if (temp > a) {
                inc = 0;
                equal = 0;
            }
            else if (temp == a) {
                inc = 0;
                dec = 0;
            }
            else if (temp < a) {
                dec = 0;
                equal = 0;
            }
        }
        
    }

    if (inc)
        printf("Increasing\n");
    else if (dec)
        printf("Decreasing\n");
    else if (equal)
        printf("Equal\n");
    else
        printf("None\n");
}