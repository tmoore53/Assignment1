//
// Created by Tyler Moore on 10/10/2021.
// 
// Main Class that executes test methods on Library class
//
#include <IOstream>
#include <cassert>
#include "library.h"

using namespace std;

void test1()
{
    //Creates and fills Library Class
    Library Libs("UWB");
    Libs.addBook("Don Quixote");
    Libs.addBook("In Search of Lost Time");
    Libs.addBook("Ulysses");
    Libs.addBook("The Odyssey");
    Libs.listAllBooks();

    // should generate already in library message and return true
    bool Result = Libs.isInLibrary("The Odyssey");
    assert(Result);

    // cannot add book twice, result should be false
    Result = Libs.addBook("The Odyssey");
    assert(!Result);

    // test remove, result should be true
    Result = Libs.removeBook("The Odyssey");
    assert(Result);

    // not in library, result should be false
    Result = Libs.isInLibrary("The Odyssey");
    assert(!Result);

    Libs.listAllBooks();

    // cannot remove twice, result should be false
    Result = Libs.removeBook("The Odyssey");
    assert(!Result);

    //Displays Library name
    cout << "Library name: " << Libs << endl;


}

//Runs all tests prompts user of successfully passing all tests
void testAll()
{
    test1();
    cout << "Successfully completed all tests." << endl;
}

int main()
{
    testAll();
    return 0;
}
