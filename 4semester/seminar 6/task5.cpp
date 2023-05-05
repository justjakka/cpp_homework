#include <iostream>
#include <string>

using namespace std;


void shiftSpaces(string& str)
{
    string temp = "";
    int counter = 0;

    for (auto i = str.begin(); i < str.end(); ++i)
    {
        if (isspace(*i))
            counter++;
        else
            temp.push_back((*i));
    }

    for (int i = 0; i < counter; i++)
        temp.push_back(' ');
    
    str = temp;
}


int main()
{
    string test = "cats and dogs";
    shiftSpaces(test);
    cout << '"' << test << '"' << endl;
}