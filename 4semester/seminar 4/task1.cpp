#include <iostream>
#include <vector>

using namespace std;


int sumEven(const vector<int>& v)
{   
    int result = 0;
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        if (!(*i % 2))
            result += *i;
    }
    return result;
}

int main()
{
    vector<int> test {4, 8, 15, 16, 23, 42};
    
    cout << sumEven(test) << endl;
}