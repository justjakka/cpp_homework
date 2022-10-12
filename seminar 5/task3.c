#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    scanf("%s", str);

    size_t n = strlen(str);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j <= i; ++j)
            printf("%c", str[j]);
        printf("\n");
    }
}