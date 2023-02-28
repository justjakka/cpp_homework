#include <iostream>
#include <string>
#include <cctype>
#include "miptstring.hpp"


using namespace std;


int main()
{
    mipt::String val1 = "Cat";
    std::cout << val1 << std::endl;

    mipt::String *val2 = new mipt::String;
    *val2 = "Dog";
    std::cout << *val2 << std::endl;
    delete val2;

    char x[sizeof(mipt::String)];
    mipt::String *val3 = new (x) mipt::String;
    *val3 = "Elephant";
    std::cout << *val3 << std::endl;
    val3->~String();
}