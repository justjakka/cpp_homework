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
    Book** books;
    int number_of_books;
};
typedef struct library Library;


void library_create(Library* lib, int num)
{
    lib->books = (Book**)malloc(sizeof(Book*) * num);
    lib->number_of_books = num;
    for (int i = 0; i < num; i++)
        lib->books[i] = (Book*)malloc(sizeof(Book));
    return;
}

void library_set(Library lib, int index, char name[], int pages, float price)
{
    lib.books[index]->pages = pages;
    lib.books[index]->price = price;
    lib.books[index]->title = (char*)malloc(sizeof(char) * 32);
    strcpy(lib.books[index]->title, name);
    return;
}

Book* library_get(Library lib, int index)
{
    return lib.books[index];
}

void library_print(Library lib)
{
    for (int i = 0; i < lib.number_of_books; i++)
        print_book(lib.books[i]);
    return;
}

void library_destroy(Library* lib)
{
    for (int i = 0; i < lib->number_of_books; i++)
    {
        free(lib->books[i]->title);
    }
    free(lib->books);
    return;
}


int main()
{
    Library a;
    library_create(&a, 3);
    library_set(a, 0, "Don Quixote", 1000, 750.0);
    library_set(a, 1, "Oblomov", 400, 250.0);
    library_set(a, 2, "The Odyssey", 500, 500.0);
    library_print(a);
    print_book(library_get(a, 1));
    library_destroy(&a);
}