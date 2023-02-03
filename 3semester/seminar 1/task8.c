#include <stdio.h>


int main(){
    int a, b, c;
    scanf("%i %i %i", &a, &b, &c);

    if (!(a % c)) {
        for (int i = a / c; i * c <= b; ++i) {
            printf("%i ", i * c);
        }
        printf("\n");
    }
    else {
        for (int i = a / c + 1; i * c <= b; ++i) {
            printf("%i ", i * c);
        }
        printf("\n");
    }
    
}