#include <iostream>


struct Book
{
    char title[100];
    int pages;
    float price;
};


bool isExpensive(Book& b)
{   
    bool res;
    if (b.price > 1000)
        res = true;
    else
        res = false;
    return res;
}


int main()
{
    Book b1 = {"a", 1, 9.0};
    Book b2 = {"b", 2, 1001.0};
    bool t1 = isExpensive(b1);
    bool t2 = isExpensive(b2);
    std::cout << t1 << "\n" << t2 << "\n";
}