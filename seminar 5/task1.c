#include <stdio.h>
#include <ctype.h>


int main()
{
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
    }
}