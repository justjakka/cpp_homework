#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <limits>

using namespace std;


template <class iterator, typename T = typename iterator::value_type> T maxElement(iterator const& con_begin, iterator const& con_end)
{   
    T max = - numeric_limits<T>::infinity();
    for (auto i = con_begin; i != con_end; ++i)
    {
        if (*i > max)
            max = *i;
    }
    return max;
}


int main()
{
    vector<int> test1 {1, 2, 425, 12341, 2314, 423, 12, 212348234, 12};
    set<int> test2 {1, 2, 425, 12341, 2314, 423, 12, 212348234, 12};
    list<int> test3 {1, 2, 425, 12341, 2314, 423, 12, 212348234, 12};

    cout << maxElement(test1.begin(), test1.end()) << endl;
    cout << maxElement(test2.begin(), test2.end()) << endl;
    cout << maxElement(test3.begin(), test3.end()) << endl;
}