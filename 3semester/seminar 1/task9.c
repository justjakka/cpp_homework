#include <stdio.h>
int check_div(int, int, int);


int main(){
    int n, a, b, c;
    scanf("%i", &n);

    a = 3;
    b = 4;
    c = 5;

    if (n > c){
        while (c <= n){
            b = 4;
            while (b < c){
                a = 3;
                while (a < b){
                    if (((a * a) + (b * b) == (c * c)) && check_div(a, b, c))
                        printf("%i %i %i\n", a, b, c);
                    ++a;
                }
                ++b;
            }
            ++c;
        }
    }
}


int check_div(int a, int b, int c){
    for (int i = 2; i <= c / 2; ++i){
        if (!((a % i) || (b % i) || (c % i)))
            return 0;
    }
    return 1;
}