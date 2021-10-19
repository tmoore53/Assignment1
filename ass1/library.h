
#ifndef ASS1_LIBRARY_H
#define ASS1_LIBRARY_H

//
// Created by Tyler Moore on 10/10/2021.
//
// Library class demonstrating partially filled arrays
// Can add/remove/find books in library
//

#include <string>

// Only for class code, OK to use namespace
using namespace std;

// Library holds books - can add, remove and list books
class Library
{
    // display all books in library
    friend ostream &operator<<(ostream &Out, const Library &Lib);

public:
    // constructor with default name
    explicit Library(const string &Name);

    // destructor
    virtual ~Library();

    // add a new book
    // return true if successful, false if
    // book already in library
    bool addBook(const string &BookName);

    // remove a book
    // return true if successfully removed
    // false if book not in library
    bool removeBook(const string &BookName);

    // list all books
    void listAllBooks() const;

    // true if book found in library
    bool isInLibrary(const string &BookName) const;

private:
    //Helper method to compare strings to each other
    bool compareString(const string &str1, const string &str2) const;

    //Helper method that returns the index of the book in the array
    int findBook(const string &name) const;

    //Max amount of Books allowed in library
    static const int MAX = 100;

    //Current number of books
    int NumberOfBooks;

    //Library inventory in array that holds title of books
    string LibraryInv[MAX];

    //The name of the Library
    string LibraryName;
};

#endif // ASS1_LIBRARY_H