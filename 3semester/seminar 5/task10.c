#include <stdio.h>
#include <ctype.h>
#include <string.h>


void safe_strcpy(char* a, size_t num, char* b)
{
    for (int i = 0; i < num - 1; i++) {
        a[i] = b[i];
        printf("%c", a[i]);
    }
    a[num - 1] = '\0';
    printf("%s", a);
}

int main()
{
    char a[10] = "Mouse";
    char b[50] = "LargeElephant";
    safe_strcpy(a, 10, b); 
}