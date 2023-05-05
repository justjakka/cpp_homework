#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() 
{
    int len;
    cin >> len;

    vector<int> numbers;

    for (int i = 0; i < len; ++i)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    auto max = max_element(numbers.begin(), numbers.end());

    sort(numbers.begin(), max);

    int counter = 0;
    vector<int> rest;

    for (auto i = max + 1; i < numbers.end(); ++i)
    {
        if (*i == *max)
        {
            *(max + 1 + counter) = *max;
            counter++;
        }
            
        else
            rest.push_back(*i);
    }

    for (int i = 0; i < rest.size(); ++i)
        *(numbers.end() - 1 - i) = *(rest.end() - 1 - i);

    for (auto i: numbers)
        cout << i << " ";
    cout << endl;
}