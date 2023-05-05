#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


bool isUpperRegister(string str)
{
    for (auto i = str.begin(); i < str.end(); ++i)
    {
        if (isalpha((*i)))
            if (islower((*i)))
                return false;
    }
    return true;
}


int main()
{
    string test1 = "Cats and Dogs!";
    string test2 = "CATS AND DOGS!";
    string test3 = "ABc123!?";
    string test4 = "ABC123!?";

    cout << isUpperRegister(test1) << endl;
    cout << isUpperRegister(test2) << endl;
    cout << isUpperRegister(test3) << endl;
    cout << isUpperRegister(test4) << endl;
}