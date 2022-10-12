#include <stdio.h>
#include <ctype.h>


int main()
{
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
}