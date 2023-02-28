#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <utility>

using namespace std;


template <typename C, typename T = typename C::value_type> vector<pair<T, T>> pairing(C const& container)
{
    vector<pair<T, T>> result;
    bool second = false;
    pair<T, T> temp;
    for (auto i: container)
    {
        if (second)
        {
            temp.second = i;
            result.push_back(temp);
            second = false;
            pair<T, T> temp;
            
        }
        else
        {
            temp.first = i;
            second = true;
        }
    }

    if (second)
    {
        temp.second = T();
        result.push_back(temp);
    }
        
    
    return result;
}

int main()
{
    std::vector v {10, 20, 30, 40, 50, 60};
    vector<pair<int, int>> a1 = pairing(v);
    cout << "[ ";
    for (auto i: a1)
        cout << "(" << i.first << ", " << i.second << ") ";

    cout << "]" << endl;


    std::array<std::string, 7> a {"cat", "dog", "mouse", "elephant", "tiget", "axolotl", "wolf"};
    vector<pair<string, string>> a2 = pairing(a);
    cout << "[ ";
    for (auto i: a2)
        cout << "(" << i.first << ", " << i.second << ") ";

    cout << "]" << endl;


    std::string s {"Cats and dogs!"};
    vector<pair<char, char>> a3 = pairing(s);
    cout << "[ ";
    for (auto i: a3)
        cout << "(" << i.first << ", " << i.second << ") ";

    cout << "]" << endl;
}