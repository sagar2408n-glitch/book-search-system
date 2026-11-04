# book-search-system
Book search and management system in C++
BOOK SEARCH SYSTEM (C++)
========================

Name:     [SAGAR]
Roll No:  [2558218]
Course:   [BCA 3RD]
Mentor:   [MS.DEVANSHI]


1. ABOUT
--------
A console-based book management and search system written in C++.
Books are stored in a text file, so data is kept between runs.


2. FEATURES
-----------
- Add a new book (title, author, year, ISBN)
- Search books by title, author or ISBN (not case sensitive)
- Show all books
- Delete a book by ISBN
- Edit a book by ISBN
- Input checking (numbers only where a number is expected)
- Automatic saving and loading from data/book.txt


3. PROJECT STRUCTURE
--------------------
booksearching/
  src/
    main.cpp       Menu and user input
    library.cpp    Library logic: load, save, add, delete, edit, search
    book.cpp       Prints a single book
  include/
    book.h         Book structure
    library.h      Library class declaration
  data/
    book.txt       Stored books (one per line)
  README.txt       This file


4. DATA FORMAT
--------------
Each line in data/book.txt is one book:

  Title|Author|Year|ISBN

Example:
  The Hobbit|J.R.R. Tolkien|1937|9780547928227


5. HOW TO COMPILE AND RUN
-------------------------
Requirements: a C++ compiler (g++), e.g. MSYS2 (UCRT64) on Windows.

1. Open a terminal in the project's main folder.
2. Compile:
     g++ src/*.cpp -Iinclude -o booksearch
3. Run (from the main folder, so data/book.txt is found):
     ./booksearch        (MSYS2 / Linux / Mac)
     booksearch.exe      (Windows Command Prompt)


6. HOW TO USE
-------------
Choose an option from the menu by typing its number:
  1 Add book      2 Search books   3 Show all
  4 Delete book   5 Edit book      0 Exit


7. CONCEPTS USED
----------------
- Structures and classes
- Vectors (std::vector) and strings (std::string)
- File input/output (fstream)
- Splitting code into header (.h) and source (.cpp) files
- Basic input validation


8. LIMITATIONS AND FUTURE WORK
------------------------------
- Data is stored in a text file; a database such as SQLite could be added.
- Console interface only; a GUI could be added later.
- Sorting and search-by-field options could be added.
- Duplicate ISBN checking can be added.
