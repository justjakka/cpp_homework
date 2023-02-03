#include <iostream>
#include <string>
#include <cctype>


using namespace std;


void truncateToDot(std::string& s) {
    int counter = -1;
    for (int i = 0; i < s.size(); i++) {
    }

    std::cout << typeid(s[1]) << std::endl; 

    if (counter != -1) {
        s.erase(s.size() - counter);
    }
}



int main() {
    std::string a = "test.aaa";
    truncateToDot(a);

    std::cout << a << std::endl;
}