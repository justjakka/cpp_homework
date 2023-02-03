#include <stdio.h>
#include <ctype.h>


int main()
{
    char str[201];
    int num;
    int x = 0;
    int y = 0;
    scanf("%i", &num);
    for (int i = 0; i < num; i++) {
        int ch;
        scanf("%s %i", str, &ch);
        if (str[0] == 'N')
            y += ch;
        if (str[0] == 'E')
            x += ch;
        if (str[0] == 'S')
            y -= ch;
        if (str[0] == 'W')
            x -= ch;
    }
    printf("%i %i", x, y);   
}