#include <stdio.h>


int main()
{
    char str1[201];
    char str2[201];
    scanf("%s", str1);
    scanf("%s", str2);
    int num;

    for (int i = 0; str1[i] * str2[i]; ++i) {
        printf("%c%c", str1[i], str2[i]);
        num = i + 1;
    }
    
    for (int i = num; str1[i]; ++i)
        printf("%c", str1[i]);
    
    for (int i = num; str2[i]; ++i)
        printf("%c", str2[i]);
}