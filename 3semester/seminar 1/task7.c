#include <stdio.h>


int main(){
    int n, m;
    int result = 0;
    scanf("%i %i", &n, &m);

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if ((i + j) % 2)
                result += -i * j;
            else
                result += i * j;
        }
    }

    printf("%i\n", result);
}