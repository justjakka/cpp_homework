#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[201];
    scanf("%200[^\n]", str);
    for(int i = 1; str[i]; ++i)
    {
        if (str[i] == ' ' && isalpha(str[i - 1]))
            printf("! ");
        else 
            printf("%c", str[i]);
        
        if (str[i + 1] == 0) {
            printf("! ");
            break;
        }
    }
}