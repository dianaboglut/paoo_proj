#include "Library.hpp"
#include "SchoolLibrary.hpp"
#include "Book.hpp"
#include <iostream>

int main(){
    Book book1("1984", "George Orwell", 1949, 328);
    Book book2("To Kill a Mockingbird", "Harper Lee", 1960, 281);
    Book book3("Clean Code", "Robert C. Martin", 2008, 180);
    Book book4("The Pragmatic Programmer", "Andrew Hunt", 1999, 352);
    Book book5("Design Patterns", "Erich Gamma", 1994, 395);
    Book book6("Effective C++", "Scott Meyers", 1992, 320);
    Book book7("The C++ Programming Language", "Bjarne Stroustrup", 2013, 1366);

    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    
    Library lib1(10);
    
    lib1.addBook(book1);
    lib1.addBook(book2);
    lib1.addBook(book3);

    std::cout << "Library 1 contains: " << std::endl;
    lib1.print();

    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------

    std::cout << "\n\tTesting Copy Constructor:" << std::endl;

    Library lib2(lib1);
    std::cout << "Library 2 (copy of Library 1) contains: " << std::endl;
    lib2.print();

    lib2.addBook(book4);
    std::cout << "After adding a book to Library 2:" << std::endl;
    std::cout << "Library 1 contains: " << std::endl;
    lib1.print();
    std::cout << "Library 2 contains: " << std::endl;
    lib2.print();

    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------

    std::cout << "\n\tTesting transferBooksTo method. Item 12:" << std::endl;

    lib1.transferBooksTo(lib2);
    std::cout << "After transferring books from Library 1 to Library 2:" << std::endl;
    std::cout << "Library 1 contains: " << std::endl;
    lib1.print();
    std::cout << "Library 2 contains: " << std::endl;
    lib2.print();

    std::cout << "\nTesting self-transfer scenario:" << std::endl;

    lib2.transferBooksTo(lib2); 

    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------

    std::cout << "\n\tTesting Copy Assignment Operator:" << std::endl;

    Library lib3(10);
    lib3.addBook(book5);

    std::cout << "Library 3 before assignment: " << std::endl;
    lib3.print();

    lib3 = lib2;
    std::cout << "Library 3 after assignment from Library 2: " << std::endl;
    lib3.print();

    lib3 = lib3; // self-assignment test
    std::cout << "Library 3 after self-assignment: " << std::endl;
    lib3.print();

    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------

    std::cout << "\n\tTesting Chained Assignment:" << std::endl;

    Library lib4(10);
    Library lib5(10);

    lib4.addBook(book6);
    lib5.addBook(book7);

    lib3 = lib4 = lib5;

    std::cout << "After the chain lib3 = lib5 = lib4: " << std::endl;
    std::cout << "lib4:\n";
    lib4.print();
    std::cout << "lib5:\n";
    lib5.print();
    std::cout << "lib3:\n";
    lib3.print();


    //------------ Use case -----------------
    
    Library myLibrary(10);
    myLibrary.addBook(book1);
    myLibrary.addBook(book2);
    myLibrary.addBook(book3);

    std::cout << "My Library:" << std::endl;
    myLibrary.print();

    Library backupLibrary = myLibrary;
    std::cout << "Backup Library:" << std::endl;
    backupLibrary.print();

    myLibrary.addBook(book4);

    std::cout << "My Library after adding a book:" << std::endl;
    myLibrary.print();
    std::cout << "Backup Library should remain unchanged:" << std::endl;
    backupLibrary.print();

    std::cout << "The system restores My Library from Backup Library." << std::endl;
    myLibrary = backupLibrary;

    std::cout << "My Library after restoration:" << std::endl;
    myLibrary.print();

    SchoolLibrary schoolLib("Central High", 10);
    schoolLib.addBook(book1);
    schoolLib.addBook(book5);
    schoolLib.print();

    std::cout << "Creating 'schoolBackup' from 'schoolLib'..." << std::endl;

    SchoolLibrary schoolBackup = schoolLib;
    schoolBackup.print();

    //--------------------------------------

    return 0;
}