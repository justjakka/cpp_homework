#include <stdio.h>
#include <string.h>


int main()
{
    char a[100];
    scanf("%s", a);
    int n = strlen(a);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            printf("%c", a[j]);
        }
        printf("\n");
    }
}