#include <stdio.h>
#include <ctype.h>


int longest_word(const char* str, char* result)
{
    int i = 0;
    int res = 0;
    int end = 0;
    while (str[i] != '\0') {
        int u = 0;
        if (i == 0) {
            while (isalpha(str[i]))
                {
                    u++;
                    i++;
                }
        }
        else if (isalpha(str[i])) {
            while (isalpha(str[i]))
                {
                    u++;
                    i++;
                }
        }
        if (u > res)
            {
                res = u;
                end = i;
            }
        i++;

    }
    for (int r = end - res; r < end; r++)
        result[r - end + res] = str[r];
    
    return res;
}

int main()
{
    char str[201];
    char result[201];
    scanf("%200[^\n]", str);
    printf("%i", longest_word(str, result));
}