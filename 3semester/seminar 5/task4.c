#include <stdio.h>


int main()
{
<<<<<<< HEAD
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
=======
    char a[100], b[100];
    scanf("%s %s", a, b);
    int size = sizeof(a);
    int size_b = sizeof(b);
    if (size < size_b)
        size = size_b;
    for (int i = 0; i < size; i++) {
        
    }
>>>>>>> 72773921ca15a67d3b2b3ead2810b5d64541ca28
}