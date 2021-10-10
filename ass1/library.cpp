// Created by XXXX on MM/DD/YYYY.
//
// Library class demonstrating partially filled arrays
// Can add/remove books from library
// findbooks in library

#include <iostream>
#include "library.h"

// constructor with default name
Library::Library(const string &Name) : LibraryName{Name}, NumberOfBooks{0}
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
        if (book == BookName)
            return true;
    }
    return false;
}

// add a new book
// return true if successful, false if
// book already in library
bool Library::addBook(const string &BookName)
{
    if (isInLibrary(BookName))
    {
        return false;
    }
    if (NumberOfBooks != MAX)
    {
        LibraryInv[NumberOfBooks] = BookName;
        NumberOfBooks++;
        return true;
    }

    return false;
}

// remove a book
// return true if successfully removed
// false if book not in library
bool Library::removeBook(const string &BookName)
{
    int index;

    for (int i{0}; i < NumberOfBooks; i++)
    {
        if (BookName == LibraryInv[i])
        {
            for (int j = i + 1; j < NumberOfBooks; j++)
            {
                LibraryInv[i] = LibraryInv[j];
                /* code */
            }
            NumberOfBooks--;

            LibraryInv[NumberOfBooks].erase();
            return true;
        }
    }

    return false;
}

// list all books
void Library::listAllBooks() const
{
    for (string book : LibraryInv)
    {
        if (!book.empty())
        {
            cout << book << endl;
        }
    }
}

ostream &operator<<(ostream &Out, const Library &Lib)
{
    return Out;
}