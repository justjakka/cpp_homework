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
            printf("%hhi", ch - 'A' + 1);
        else
            printf("%hhi", ch - 'a' + 1);
    }

    else 
        printf("Not a letter");
=======
    char a[2];
    scanf("%1s", a);
    if (isalpha(a[0])) {
        printf("%i\n", toupper(a[0]) - 64);
    }
    else
        printf("Not a letter\n");
>>>>>>> 72773921ca15a67d3b2b3ead2810b5d64541ca28
}