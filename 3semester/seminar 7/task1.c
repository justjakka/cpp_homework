#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct book
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;


void print_book(struct book b) {
    printf("Book info:\n");
    printf("Title: %s\nPages: %d\nPrice: %g\n\n", b.title, b.pages, b.price);
}


int main()
{
    long long* bignum = (long long*)malloc(3 * sizeof(long long));
    *bignum = 123;
    printf("%lli\n", *bignum);
    free(bignum);

    char *eleph;
    eleph = (char*)malloc(sizeof(char) * (9));
    strcpy(eleph, "Elephant");
    printf("%s\n", eleph);
    free(eleph);

    char** cats = (char**)malloc(sizeof(char*));
    *cats = (char*)malloc(sizeof(char) * 14);
    strcpy(*cats, "Cats and Dogs");
    printf("%s\n", *cats);
    free(*cats);
    free(cats);

    Book *b = malloc(sizeof(Book));
    b->pages = 1000;
    strcpy(b->title, "Don Quixote");
    b->price = 750.0;
    print_book(*b);
    free(b);


    Book bk = {"Don Quixote", 1000, 750.0};
    Book** r = (Book**)malloc(sizeof(Book*));
    *r = &bk;
    print_book(**r);
    free(r);

    Book** bks = (Book**)malloc(sizeof(Book*));
    *bks = (Book*)malloc(sizeof(Book));
    strcpy((*bks)->title, "Don Quixote");
    (*bks)->pages = 1000;
    (*bks)->price = 750.0;
    print_book(**bks);
    free(*bks);
    free(bks);

    Book* books = (Book*)malloc(sizeof(Book) * 3);
    strcpy(books[0].title, "Don Quixote");
    strcpy(books[1].title, "Oblomov");
    strcpy(books[2].title, "The Odyssey");
    books[0].pages = 1000;
    books[1].pages = 400;
    books[2].pages = 500;
    books[0].price = 750.0;
    books[1].price = 250.0;
    books[2].price = 500.0;

    print_book(books[0]);
    print_book(books[1]);
    print_book(books[2]);
    free(books);
    
}