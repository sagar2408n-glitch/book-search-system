#include "book.h"
#include <iostream>

void printBook(const Book& b) {
    std::cout << b.title << " by " << b.author
              << " (" << b.year << ") ISBN: " << b.isbn << "\n";
}