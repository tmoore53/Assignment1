//
// Created by Tyler Moore on 10/10/2021.
//
// Implementation file of: Library Class
//
// Library class demonstrating partially filled arrays
// Can add/remove/find books in library
//

#include "library.h"
#include <iostream>

// constructor with default name
explicit Library::Library(const string &Name) : LibraryName{Name}, NumberOfBooks{0}
{
}

// destructor
// nothing on heap
Library::~Library()
{
    // destructor
}

// true if book found in library
bool Library::isInLibrary(const string &BookName) const
{
    for (string book : LibraryInv)
    {
        if (compareString(BookName, book))
        {
            return true;
        }
    }
    return false;
}

// add a new book
// return true if successful, false if
// book already in library
bool Library::addBook(const string &BookName)
{
    // Checks if book is already in library
    if (isInLibrary(BookName))
    {
        cout << "Book already exists in library" << endl;
        return false;
    }
    // Checks if library is full
    // If it's not it will add the book and
    // increment the number of books in the library
    if (NumberOfBooks != MAX)
    {
        LibraryInv[NumberOfBooks] = BookName;
        NumberOfBooks++;
        return true;
    }
    cout << "Library is full of books" << endl;

    return false;
}

// remove a book
// return true if successfully removed
// false if book not in library
// Decreases Number of books if true
bool Library::removeBook(const string &BookName)
{
    int index = findBook(BookName);

    if (index >= 0)
    {
        LibraryInv[index] = LibraryInv[NumberOfBooks - 1];

        NumberOfBooks--;

        LibraryInv[NumberOfBooks].erase();

        return true;
    }

    return false;
}

// list all books
void Library::listAllBooks() const
{
    // Print all the strings in the library if they
    // are not empty
    for (string book : LibraryInv)
    {
        if (!book.empty())
        {
            cout << book << endl;
        }
    }
}

//Helper method to compare strings to each other
bool Library::compareString(const string &str1, const string &str2) const
{

    int compareNum = str1.compare(str2);
    if (compareNum == 0)
    {
        return true;
    }
    return false;
}

//Helper method that returns the index of the book in the array
int Library::findBook(const string &name) const
{
    for (int i{0}; i < NumberOfBooks; i++)
    {
        if (compareString(name, LibraryInv[i]))
            return i;
    }
    return -1;
};

//Operator << is overridden to display the name of the
//library
ostream &operator<<(ostream &Out, const Library &Lib)
{
    return Out << Lib.LibraryName;
}
