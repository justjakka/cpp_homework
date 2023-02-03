#include <stdio.h>
#include <ctype.h>


int main()
{
    char str[201];
    int num = 0;
    scanf("%s", str);
    for(int i = 0; str[i]; ++i) {
        if (str[i] == '(')
            num++;
        else
            num--;

        if (num == -1)
            break;
    }
    
    if (num != 0)
        printf("No");
    else
        printf("Yes");
}