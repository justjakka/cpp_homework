#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <forward_list>

using namespace std;


template <class iterator, typename T = typename iterator::value_type> void swapNeighbours(iterator const& con_begin, iterator const& con_end)
{   
    int size = distance(con_begin, con_end);

    if (size % 2)
        size--;

    for (int i = 0; i < size; ++i)
    {
        if (i % 2)
            continue;
        else
        {
            iterator iter = con_begin;
            advance(iter, i);
            T temp1 = *(iter);
            advance(iter, 1);
            T temp2 = *(iter);
            *(iter) = temp1;
            iter = con_begin;
            advance(iter, i);
            *(iter) = temp2;
        }
        
    }
    return;
}


int main()
{
    vector<int> test1 {10, 20, 30, 40, 50};
    swapNeighbours(test1.begin(), test1.end());

    for (auto i: test1)
        cout << i << " ";
    cout << endl;

    swapNeighbours(test1.begin(), test1.begin() + 3);

    for (auto i: test1)
        cout << i << " ";
    cout << endl;

    list<int> test2 {10, 20, 30, 40, 50};
    swapNeighbours(test2.begin(), test2.end());

    for (auto i: test2)
        cout << i << " ";
    cout << endl;

    forward_list<int> test3 {10, 20, 30, 40, 50};
    swapNeighbours(test3.begin(), test3.end());

    for (auto i: test3)
        cout << i << " ";
    cout << endl;
}