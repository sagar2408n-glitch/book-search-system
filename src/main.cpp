#include <iostream>
#include <string>
#include <limits>
#include "book.h"
#include "library.h"

// Reads a whole number safely; asks again if the input is not a number
int readInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number.\n";
    }
}

Book readBook() {
    Book b;
    std::cout << "Title: ";  std::getline(std::cin, b.title);
    std::cout << "Author: "; std::getline(std::cin, b.author);
    b.year = readInt("Year: ");
    std::cout << "ISBN: ";   std::getline(std::cin, b.isbn);
    return b;
}

int main() {
    Library lib;
    const std::string fileName = "data/book.txt";
    lib.load(fileName);

    int choice;
    do {
        std::cout << "\n--- Book Search System ---\n"
                  << "1. Add book\n"
                  << "2. Search books\n"
                  << "3. Show all\n"
                  << "4. Delete book\n"
                  << "5. Edit book\n"
                  << "0. Exit\n";
        choice = readInt("Choice: ");

        if (choice == 1) {
            Book b = readBook();
            lib.addBook(b);
            lib.save(fileName);
            std::cout << "Book added!\n";
        } else if (choice == 2) {
            std::string keyword;
            std::cout << "Search keyword: ";
            std::getline(std::cin, keyword);
            lib.search(keyword);
        } else if (choice == 3) {
            lib.showAll();
        } else if (choice == 4) {
            std::string isbn;
            std::cout << "ISBN of the book to delete: ";
            std::getline(std::cin, isbn);
            if (lib.deleteBook(isbn)) {
                lib.save(fileName);
                std::cout << "Book deleted.\n";
            } else {
                std::cout << "No book with that ISBN.\n";
            }
        } else if (choice == 5) {
            std::string isbn;
            std::cout << "ISBN of the book to edit: ";
            std::getline(std::cin, isbn);
            std::cout << "Enter the new details:\n";
            Book updated = readBook();
            if (lib.editBook(isbn, updated)) {
                lib.save(fileName);
                std::cout << "Book updated.\n";
            } else {
                std::cout << "No book with that ISBN.\n";
            }
        } else if (choice != 0) {
            std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    std::cout << "Goodbye!\n";
    return 0;
}