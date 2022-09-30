#include <stdio.h>
#include <ctype.h>


int main()
{
    char a[2];
    scanf("%1s", a);
    if (isalpha(a[0])) {
        if (isupper(a[0]))
            printf("Uppercase Letter\n");
        else
            printf("Lowercase Letter\n");
    }
    else {
        if (isdigit(a[0]))
            printf("Digit\n");
        else 
            printf("Other\n");
    }
}