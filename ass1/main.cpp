//Why does this get red lines?
#include <iostream>
#include <cassert>
#include "library.h"

using namespace std;

void test1()
{
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
}

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
