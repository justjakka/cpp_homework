#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct book
{
    char* title;
    int pages;
    float price;
};
typedef struct book Book;

void print_book(struct book* b) {
    printf("Book info:\n");
    printf("Title: %s\nPages: %d\nPrice: %g\n\n", b->title, b->pages, b->price);
}

struct library
{
    Book* books;
    int number_of_books;
};
typedef struct library Library;


void library_create(Library* lib, int num)
{
    lib->books = (Book*)malloc(sizeof(Book) * num);
    lib->number_of_books = num;
    return;
}

void library_set(Library lib, int index, char name[], int pages, float price)
{
    lib.books[index].pages = pages;
    lib.books[index].price = price;
    lib.books[index].title = malloc(sizeof(char) * 32);
    strcpy(lib.books[index].title, name);
    return;
}

Book* library_get(Library lib, int index)
{
    Book* res = &(lib.books[index]);
    return res;
}

void library_print(Library lib)
{
    for (int i = 0; i < lib.number_of_books; i++)
        print_book(&(lib.books[i]));
    return;
}

void library_destroy(Library* lib)
{
    for (int i = 0; i < lib->number_of_books; i++)
    {
        free(lib->books[i].title);
    }
    free(lib->books);
    return;
}


int main()
{
    Book* p = (Book*)malloc(sizeof(Book));
    p->pages = 1000;
    p->price = 750.0;
    p->title = malloc(sizeof(char) * 32);
    strcpy(p->title, "Don Quixote");
    print_book(p);
    free(p);

    Book* books = (Book*)malloc(sizeof(Book) * 3);
    books[0].pages = 1000;
    books[1].pages = 400;
    books[2].pages = 500;
    books[0].price = 750.0;
    books[1].price = 250.0;
    books[2].price = 500.0;

    books[0].title = malloc(sizeof(char) * 32);
    books[1].title = malloc(sizeof(char) * 32);
    books[2].title = malloc(sizeof(char) * 32);

    strcpy(books[0].title, "Don Quixote");
    strcpy(books[1].title, "Oblomov");
    strcpy(books[2].title, "The Odyssey");


    print_book(&books[0]);
    print_book(&books[1]);
    print_book(&books[2]);
    free(books);

    Library a;
    library_create(&a, 3);
    library_set(a, 0, "Don Quixote", 1000, 750.0);
    library_set(a, 1, "Oblomov", 400, 250.0);
    library_set(a, 2, "The Odyssey", 500, 500.0);
    library_print(a);
    print_book(library_get(a, 1));
    library_destroy(&a);
}