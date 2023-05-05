#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void reverseAll(vector<string>& str)
{
    reverse(str.begin(), str.end());
    for (auto i = str.begin(); i < str.end(); i++)
        reverse((*i).begin(), (*i).end());
    return;
}


int main()
{
    vector<string> test1 = {"cat", "dog", "mouse", "elephant"};
    vector<string> test2 = {"a", "vc"};
    
    reverseAll(test1);
    reverseAll(test2);

    for (auto i: test1)
        cout << i << " ";
    cout << endl;

    for (auto i: test2)
        cout << i << " ";
    cout << endl;
}