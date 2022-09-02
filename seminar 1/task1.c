#include <stdio.h>


int main(){
    int number;
    scanf("%i", &number);
    if ((number >= 0 && number < 200) && (number <= 20 || number > 100) && !(number % 2))
        printf("Yes\n");
    else
        printf("No\n");
}