#include <iostream>
#include <string>
#include <cctype>


using namespace std;


int stringSum(std::string str) 
{
    int result = 0;
    int counter = str.length() - 1;

    while (counter >= 1)
    {
        int pow = 1;

        while (isdigit(str[counter]))
        {
            result += (str[counter] - 48) * pow;
            pow *= 10;
            counter--;
        }

        counter--;
    }

    return result;
}


int main()
{
    std::string test1{};
    std::string test2{"[10, 20, 30, 40, 50]"};

    std::cout << stringSum(test1) << " " << stringSum(test2) << std::endl;
}