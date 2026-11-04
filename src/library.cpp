#include "library.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

static std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

void Library::load(const std::string& fileName) {
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Book b;
        std::string yearStr;
        std::getline(ss, b.title, '|');
        std::getline(ss, b.author, '|');
        std::getline(ss, yearStr, '|');
        std::getline(ss, b.isbn, '|');
        if (yearStr.empty()) continue;
        b.year = std::stoi(yearStr);
        books.push_back(b);
    }
}

void Library::save(const std::string& fileName) const {
    std::ofstream file(fileName);
    for (const Book& b : books)
        file << b.title << '|' << b.author << '|' << b.year << '|' << b.isbn << '\n';
}

void Library::addBook(const Book& b) {
    books.push_back(b);
}

bool Library::deleteBook(const std::string& isbn) {
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].isbn == isbn) {
            books.erase(books.begin() + i);
            return true;
        }
    }
    return false;
}

bool Library::editBook(const std::string& isbn, const Book& updated) {
    for (Book& b : books) {
        if (b.isbn == isbn) {
            b = updated;
            return true;
        }
    }
    return false;
}

void Library::search(const std::string& keyword) const {
    std::string key = toLower(keyword);
    bool found = false;
    for (const Book& b : books) {
        if (toLower(b.title).find(key) != std::string::npos ||
            toLower(b.author).find(key) != std::string::npos ||
            toLower(b.isbn).find(key) != std::string::npos) {
            printBook(b);
            found = true;
        }
    }
    if (!found) std::cout << "No books found.\n";
}

void Library::showAll() const {
    if (books.empty()) std::cout << "No books yet.\n";
    for (const Book& b : books) printBook(b);
}