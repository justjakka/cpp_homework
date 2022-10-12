#include <stdio.h>


void  is_palindrom(char str[201]);

size_t length(char* str)
{
    int i = 0;
    while (str[i] != '\0')
        ++i;

    return i;
}

void is_palindrom(char str[201])
{
    int len = length(str);
    int flag = 0;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            flag = 1;
            break;
        }
    }
    if (flag)
        printf("No");
    else
        printf("Yes");
}


int main()
{
    char str[201];
    scanf("%200s", str);
    is_palindrom(str);
}

