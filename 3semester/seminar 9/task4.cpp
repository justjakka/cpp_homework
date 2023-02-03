#include <iostream>
#include <ctype.h>


void countLetters(const char* str, int& numLetters, int& numDigits, int& numOther)
{
    int i = 0;
    while (str[i] != 0)
    {
        if (isalpha(str[i]))
        {
            numLetters++;
            i++;
        }
        else if (isdigit(str[i]))
        {
            numDigits++;
            i++;
        }
        else
        {
            numOther++;
            i++;
        }
    }
}


int main()
{
    char e[32] = "test123)";
    char* r = e;
    int l = 0;
    int d = 0;
    int o = 0;
    int& L = l;
    int& D = d;
    int& O = o;
    countLetters(r, L, D, O);
    std::cout << L << "\n" << D << "\n" << O << "\n";
}