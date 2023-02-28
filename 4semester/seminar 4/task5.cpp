#include <iostream>
#include <vector>

using namespace std;


template <typename T> T maximum(vector<T> v)
{
    T result = v[0];
    for (auto i: v)
        {
            if (result < i)
                result = i;
        }
    
    return result;
}


int main()
{
    vector<int> test1 {1, 2, 3, 4, 5, 6};

    cout << maximum(test1) << endl;

    vector<float> test2 {1.2, 2.3, 5.3, 2.1, 10.2, 10.3, 12.67};

    cout << maximum(test2) << endl;

    vector<string> test3 {"a", "abv", "asfasdgasfg", "boasdz", "abasd"};
    cout << maximum(test3) << endl;

    vector<pair<int, int>> test4{{1, 2}, {2, 3}, {3, 4}, {5, 6}, {12, 0}, {0, 0}};
    pair<int, int> res = maximum(test4);
    cout << res.first << " " << res.second << endl;
}