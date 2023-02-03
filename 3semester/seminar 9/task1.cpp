#include <iostream>

namespace myspace 
{
    void printNTimes(const char* str, int n = 10)
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << str << '\n';
        }
    }
}

int main()
{
    const char text[6] = "test";
    myspace::printNTimes(text);
}