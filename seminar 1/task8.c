#include <stdio.h>


int main(){
    int a, b, c;
    scanf("%i %i %i", &a, &b, &c);

    for (int i = a; i <= b; ++i){
        if (!(i % c))
            printf("%i ", i);
    }
    printf("\n");
}