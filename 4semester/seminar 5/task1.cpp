#include <iostream>
#include <list>
using namespace std;


int main()
{
    int n, m;
    cin >> n;
    cin >> m;

    m--;

    list<int> warriors;

    for (int i = 1; i <= n; i++)
        warriors.push_back(i);

    int position = 0;

    while (warriors.size() != 1)
    {
        auto iterator = warriors.begin();
        position = (position + m) % warriors.size();
        advance(iterator, position);
        cout << *iterator << " ";
        warriors.erase(iterator);
    }

    cout << endl;

    cout << warriors.front() << endl;
}