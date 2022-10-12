#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(int argc, char** argv)
{
    int temp;
    sscanf(argv[2], "%i", &temp);
    for (int i = 0; i < temp; i++)
        printf("%s ", argv[1]);
}