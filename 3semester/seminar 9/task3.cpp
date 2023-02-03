#include <iostream>


int cubeV(const int& r)
{
    int res = r * r * r;
    return res;
}


int main()
{
    int k = 10;
    std::cout << cubeV(k) << "\n";
}
