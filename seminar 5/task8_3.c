#include <stdio.h>
#include <ctype.h>
#include <string.h>


int deletechar(char *str, int pos, int num1, int num2, char ch)
{
    for (int i = pos; i < num1; ++i) {
        if (str[i + num2] == ch){
            return i;
        }
        str[i]=str[i + num2];
    }
    return 201;
}

void delete_chars(char* str, char ch, int len)
{
    int num = 1;
    int i = 0;
    while (str[i] != ch)
        i++;
    if (str[i] == ch) {
            i = deletechar(str, i, len, num, ch);
            num++;
        }
    while (i < len) {
        i = deletechar(str, i, len, num, ch);
        num++;
    }
}

int main()
{
    char str[201];
    char ch;
    
    scanf("%s %c", str, &ch);
    int len = strlen(str);
    delete_chars(str, ch, len);
}



