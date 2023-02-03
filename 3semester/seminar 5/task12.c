#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(int argc, char** argv)
{
    int y = argc;
    int a[100];
    for (int i = 1; i < y; i++)
        a[i] = i;
    
    for (int j = 1; j < y; ++j) {
        for (int i = 1; i < y-j; ++i) {
            if (strcmp(argv[a[i]], argv[a[i + 1]]) == 1) {
                int ch = a[i];
                a[i] = a[i + 1];
                a[i + 1] = ch;
            }
        }
    }

    for (int i = 1; i < y; i++)
        printf("%s ", argv[a[i]]);
}