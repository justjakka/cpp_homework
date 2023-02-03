#include <stdio.h>
#include <ctype.h>


void encrypt(char* str, int k);

size_t length(char* str)
{
    int i = 0;
    while (str[i] != '\0')
        ++i;

    return i;
}

void shift(char ch, int num)
{
    if (isalpha(ch)) {
        if (isupper(ch))
            printf("%c", ((ch - 'A' + num) % 26 +'A'));
        else
            printf("%c", ((ch - 'a' + num) % 26 +'a'));
    }
    else
        printf("%c", ch);
}

void encrypt(char* str, int num)
{
    int len = length(str);
    for (int i = 0; i < len; i++)
        shift(str[i], num);
}

int main()
{
    char str[201];
    int num;
    scanf("%i %200[^\n]", &num, str);
    encrypt(str, num);
    
}
