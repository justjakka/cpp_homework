#include <iostream>
#include <set>
#include <vector>

using namespace std;



void ropeCycle(int n, const std::vector<int>& v)
{
	std::set<int> sections = {0, n};
	std::multiset<int> sizes = {n};

	std::set<int>::iterator low, high, eq;
	int s, l, r;

	std::multiset<int>::reverse_iterator it;
	std::multiset<int>::iterator d;

	for (int i : v)
	{
		sections.insert(i);

		high = sections.upper_bound(i);
		low = sections.lower_bound(i);
		low--;
		eq = sections.find(i);

		s = *high - *low;
		r = *high - *eq;
		l = *eq - *low;

		d = sizes.find(s);
		sizes.erase(d);

		sizes.insert(r);
		sizes.insert(l);

		it = sizes.crbegin();

		cout << *it << ' ';
	}
	cout << endl;
}



int main()
{
	int n, k;
	cin >> n >> k;

	std::vector<int> cuts;

	for (int i = 0; i < k; ++i)
	{
		int j;
		cin >> j;
		cuts.push_back(j);
	}

	const std::vector<int>& pcuts = cuts;
	ropeCycle(n, cuts);
}