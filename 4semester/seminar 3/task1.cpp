#include <iostream>
#include <string>
#include <cctype>


using namespace std;


int main() {
    std::string input;
    std::getline (std::cin, input);

    int res = input.compare("");

    if (res)
        {
            if (islower(input[0]))
                input[0] = toupper(input[0]);
            else
                input[0] = tolower(input[0]);
            
            std::cout << input << std::endl;
        }
    else
        std::cout << std::endl;
}