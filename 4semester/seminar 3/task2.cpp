#include <iostream>
#include <string>
#include <cctype>


using namespace std;


std::string repeat1(std::string_view s) {
    std::string res = {s.begin(), s.end()};
    res += s;
    return res;
}


void repeat2(std::string& s) {
    std::string temp = s;
    s += temp;
}


void repeat3(std::string* ps) {
    std::string temp = *ps;
    *ps += temp;
}


std::string* repeat4(std::string_view s) {
    int size = s.length();

    std::string* res = new std::string[2 * size];

    *res += s;
    *res += s;
    return res;
}



int main() {
    std::string a = "Test";

    std::string out1 = repeat1(a);

    std::cout << out1 << std::endl;

    std::string b = "Tested";

    repeat2(b);

    std::cout << b << std::endl;

    repeat3(&b);

    std::cout << b << std::endl;


    std::string* out2 = repeat4(a);

    std::cout << *out2 << std::endl;

}