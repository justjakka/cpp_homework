#include <iostream>
#include <vector>
#include <limits>
#include <functional>

using namespace std;

template <class iterator, typename T = typename iterator::value_type> 
iterator bestNeighbours(iterator const& con_begin, iterator const& con_end, T (*func)(T, T))
{
    iterator result;
    iterator end = con_begin;
    T max = -numeric_limits<T>::infinity();
    advance(end, distance(con_begin, con_end) - 1);
    for (auto i = con_begin; i != end; advance(i, 1))
    {
        T val1 = *i;
        iterator temp = i;
        advance(temp, 1);
        T val2 = *temp;

        if (func(val1, val2) > max)
            result = i;
    }

    return result;
}


int main()
{
    vector<int> v {50, 10, 10, 20, 90, 30, 40, 60, 80, 20};
    auto it = bestNeighbours(v.begin(), v.end(), [](int a, int b){return a + b;});
    // не работает :(
}