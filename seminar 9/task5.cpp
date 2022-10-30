#include <iostream>


struct Book
{
    char title[100];
    int pages;
    float price;
};


void addPrice(Book& b, float num)
{
    b.price += num;
    return;
}


int main()
{
    Book test = {"teastastr", 1000, 10.0};
    Book& r = test;
    addPrice(r, 5.0);
    std::cout << r.price << "\n";
}