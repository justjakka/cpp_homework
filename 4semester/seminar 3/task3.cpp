#include <iostream>
#include <string>
#include <cctype>


using namespace std;


std::string operator*(const std::string s, int n) {
    std::string res = "";

    for (int i = 0; i < n; i++) {
        res += s;
    }

    return res;
}



int main() {
    std::string a = "a";
    std::cout << a * 5 << std::endl;
}