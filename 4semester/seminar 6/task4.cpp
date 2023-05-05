#include <iostream>
#include <string>
#include <cstring>

using namespace std;


bool isIdentifier(string_view str)
{   
    if (!(isalpha(*str.begin()) || *str.begin() == '_'))
        return false;
    for (auto i = str.begin(); i < str.end(); ++i)
    {   
        if (!isalnum((*i)))
        {
            if ((*i) != '_')
                return false;
        }
    }
    return true;
}


int main()
{
    string test;
    cin >> test;
    string_view v = test;
    cout << isIdentifier(v) << endl;
}