#include <stdio.h>
#include <string.h>

<<<<<<< HEAD
int main()
{
    char str[1000];
    scanf("%s", str);

    size_t n = strlen(str);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j <= i; ++j)
            printf("%c", str[j]);
=======

int main()
{
    char a[100];
    scanf("%s", a);
    int n = strlen(a);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            printf("%c", a[j]);
        }
>>>>>>> 72773921ca15a67d3b2b3ead2810b5d64541ca28
        printf("\n");
    }
}