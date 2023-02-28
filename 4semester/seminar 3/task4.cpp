#include <iostream>
#include <string>
#include <cctype>


using namespace std;


void truncateToDot(std::string& s) {
    int i = s.find(".");
	s.erase(i);
	return;
}



int main() {
    std::string a = ".aaa";
    
    truncateToDot(a);

    std::cout << a << std::endl;
}