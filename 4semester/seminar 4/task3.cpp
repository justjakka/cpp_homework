#include <iostream>
#include <vector>

using namespace std;


int floorSqrt(int x)
{
    if (x == 0 || x == 1)
        return x;
 
    int i = 1, result = 1;
    while (result <= x) {
        i++;
        result = i * i;
    }
    return i - 1;
}


bool isPrime(int n)
{   
    bool is_prime = true;
    for (int i = 2; i <= floorSqrt(n); ++i) {
        if (n % i == 0) {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}



vector<int> getPrimes(int n)
{   
    vector<int> result;
    result.push_back(2);
    for (int i = 3; i <= floorSqrt(n); i += 2)
    {
        if (isPrime(i))
            result.push_back(i);
    }
    return result;
}


vector<pair<int, int>> factorization(int n)
{
    vector<pair<int, int>> result;
    vector<int> primes = getPrimes(n);

    for (auto i = primes.begin(); i != primes.end(); ++i)
    {
        pair<int, int> temp;
        temp.second = 0;
        temp.first = *i;

        while (!(n % *i))
        {
            temp.second += 1;
            n /= *i;
        }

        if (temp.second != 0)
            result.push_back(temp);
    }

    if (result.size() == 0)
    {
        pair<int, int> temp(n, 1);
        result.push_back(temp);
    }

    return result;
}


int main()
{
    vector<pair<int, int>> test1 = factorization(60);
    for (auto i: test1)
        cout << "{" << i.first << ", " << i.second << "}" << endl;
    
    cout << endl;

    vector<pair<int, int>> test2 = factorization(626215995);
    for (auto i: test2)
        cout << "{" << i.first << ", " << i.second << "}" << endl;

    cout << endl;

    vector<pair<int, int>> test3 = factorization(107);
    for (auto i: test3)
        cout << "{" << i.first << ", " << i.second << "}" << endl;
    
    cout << endl;

    vector<pair<int, int>> test4 = factorization(1);
    for (auto i: test4)
        cout << "{" << i.first << ", " << i.second << "}" << endl;

}