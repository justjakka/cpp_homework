#include <iostream>
#include <string>
#include <cctype>


using namespace std;


int main()
{
    int *val1 = new int;
    *val1 = 123;
    std::cout << *val1 << std::endl;

    delete val1;

    std::string *val2 = new std::string;
    *val2 = "Cats and Dogs";
    std::cout << *val2 << std::endl;

    delete val2;

    int* val3 = new int[5] {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++)
        std::cout << val3[i] << " ";
    std::cout << std::endl;

    delete[] val3;


    std::string* val4 = new std::string[3] {"Cat", "Dog", "Mouse"};
    for (int i = 0; i < 3; i++)
        std::cout << val4[i] << " ";
    std::cout << std::endl;

    std::string_view* val5 = new std::string_view[3];
    for (int i = 0; i < 3; i++)
    {
        val5[i] = val4[i];
        std::cout << val5[i] << " ";
    }
    std::cout << std::endl;

    delete[] val5;
    delete[] val4;
}