#include <iostream>
#include <vector>

using namespace std;


vector<int> lastDigits1(const vector<int>& v)
{   
    vector<int> result;
    for (auto i = v.begin(); i != v.end(); ++i)
        result.push_back(*i % 10);
    return result;
}

void lastDigits2(vector<int>& v)
{   
    vector<int> result;
    for (auto i = v.begin(); i != v.end(); ++i)
        *i = *i % 10;
    return;
}

void lastDigits3(vector<int>* v)
{   
    vector<int> result;
    for (auto i = v->begin(); i != v->end(); ++i)
        *i = *i % 10;
    return;
}

/*
void lastDigits4(span<int> sp)
{
    return;
}

results in an error, see traceback below:

task2.cpp:31:6: error: variable or field ‘lastDigits4’ declared void
   31 | void lastDigits4(span<int> sp)
      |      ^~~~~~~~~~~
task2.cpp:31:18: error: ‘span’ was not declared in this scope
   31 | void lastDigits4(span<int> sp)
      |                  ^~~~
task2.cpp:31:23: error: expected primary-expression before ‘int’
   31 | void lastDigits4(span<int> sp)

*/

int main()
{
    vector<int> test1 {4, 8, 15, 16, 23, 42};

    vector<int> res1 = lastDigits1(test1);
    for (auto i = res1.begin(); i != res1.end(); ++i)
        cout << *i << " ";
    cout << endl;

    lastDigits2(test1);
    for (auto i = test1.begin(); i != test1.end(); ++i)
        cout << *i << " ";
    cout << endl;

    vector<int> test2 {4, 8, 15, 16, 23, 42};
    lastDigits3(&test2);
    for (auto i = test2.begin(); i != test2.end(); ++i)
        cout << *i << " ";
    cout << endl;
}