#include <iostream>
#include <map>

using namespace std;


int main()
{
    map<int, int> numbers;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if (numbers.count(temp) == 0)
            numbers.insert(pair<int, int>(temp, 1));
        else
            numbers[temp] += 1;
    }

    for (auto iter = numbers.begin(); iter != numbers.end(); ++iter)
        cout << iter->first << ": " << iter->second << endl;
    
}