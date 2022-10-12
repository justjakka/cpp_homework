#include <stdio.h>
#include <ctype.h>


int main()
{
<<<<<<< HEAD
    char ch;
    scanf("%c", &ch);
    if (isalpha(ch)) 
    {
        if (isupper(ch))
            printf("Uppercase Letter");
        else
            printf("Lowercase Letter");
    }
    
    else 
    {
        if (isdigit(ch))
            printf("Digit");
        else 
            printf("Other");
=======
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
>>>>>>> 72773921ca15a67d3b2b3ead2810b5d64541ca28
    }
}