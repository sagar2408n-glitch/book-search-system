#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "book.h"

class Library {
public:
    void load(const std::string& fileName);
    void save(const std::string& fileName) const;
    void addBook(const Book& b);
    bool deleteBook(const std::string& isbn);
    bool editBook(const std::string& isbn, const Book& updated);
    void search(const std::string& keyword) const;
    void showAll() const;

private:
    std::vector<Book> books;
};

#endif