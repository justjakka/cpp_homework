#include <stdio.h>


int main()
{
    char a[100], b[100];
    scanf("%s %s", a, b);
    int size = sizeof(a);
    int size_b = sizeof(b);
    if (size < size_b)
        size = size_b;
    for (int i = 0; i < size; i++) {
        
    }
}