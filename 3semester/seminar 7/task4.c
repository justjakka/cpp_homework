#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char** load_lines(const char* filename)
{
    FILE* file = fopen(filename, "r");


    int lines = 1;

    while (1)
    {
        int ch = fgetc(file);
        if (ch == EOF)
            break;

        else if (ch == 10)
            lines++;

        else
            continue;
    }

    char** res = (char**)malloc((lines + 1) * sizeof(char*));

    fseek(file, 0, SEEK_SET);

    int* temp = (int*)malloc(lines * sizeof(int));

    int counter = 0;
    int line = 0;

    while (1)
    {
        int ch = fgetc(file);
        if (ch == EOF)
        {
            temp[line] = counter;
            break;
        }
            
        else if (ch == 10)
        {
            temp[line] = counter;
            counter = 0;
            line++;
        }
            
        else
            counter++;
        
    }

    for (int i = 0; i < lines; i++)
        res[i] = (char*)malloc((temp[i] + 1) * sizeof(char));
    
    free(temp);

    fseek(file, 0, SEEK_SET);

    line = 0;
    counter = 0;

    while (1)
    {
        int ch = fgetc(file);
    
        if (ch == EOF)
        {
            res[line][counter] = 0;
            line++;
            break;
        }
            
        else if (ch == 10)
        {
            res[line][counter] = 0;
            counter = 0;
            line++;
        }
            
        else
        {
            res[line][counter] = ch;
            counter++;
        }
    }
    fclose(file);

    res[line] = NULL;

    return res;
}


void destroy_strings(char** p_string_array)
{
    int i = 0;
    while (p_string_array[i] != NULL)
    {
        free(p_string_array[i]);
        i++;
    }
    free(p_string_array);
}


void sort_strings(char** words)
{
    int len = 1;

    while (words[len] != NULL)
        len++;
    
    for (int j = 0; j < len; ++j)
    {
        for (int i = 0; i < len - 1 - j; i += 1)
        {
            if (strcmp(words[i], words[i + 1]) > 0)
            {
                char* temp = words[i];
                words[i] = words[i + 1];
                words[i + 1] = temp;
            }
        }
    }
}


int main(int argc, char** argv)
{
    char** lines = load_lines(argv[1]);
    sort_strings(lines);

    FILE* output = fopen(argv[2], "w");

    int i = 0;
    while (lines[i] != NULL)
    {
        int j = 0;
        while (lines[i][j] != 0)
        {
            fputc(lines[i][j], output);
            j++;
        }
        fputc(10, output);
        i++;
    }

    fclose(output);
    
    destroy_strings(lines);
}