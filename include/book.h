#ifndef BOOK_H
#define BOOK_H

#include <string>

struct Book {
    std::string title;
    std::string author;
    int year;
    std::string isbn;
};

void printBook(const Book& b);

#endif