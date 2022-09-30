#include <stdio.h>
#include <ctype.h>


int main()
{
    char a[2];
    scanf("%1s", a);
    if (isalpha(a[0])) {
        printf("%i\n", toupper(a[0]) - 64);
    }
    else
        printf("Not a letter\n");
}