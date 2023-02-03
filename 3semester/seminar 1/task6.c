#include <stdio.h>
#include <limits.h>
int get_length(int);


int main(){
    int a, b;
    scanf("%i %i", &a, &b);
    int max = a;
    int max_length = get_length(a);
    for (int i = a + 1; i <= b; ++i){
        int temp = get_length(i);
        if (temp > max_length){
            max = i;
            max_length = temp;
        }
    }
    
    printf("%i %i", max, max_length);
}

int get_length(int n) {
    int length = 1;
    while (!(n == 1)){
        ++length;
        if (!(n % 2))
            n /= 2;
        else
            n = 3 * n + 1;
    }
    return length;
}