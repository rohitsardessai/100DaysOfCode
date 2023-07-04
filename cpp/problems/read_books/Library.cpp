#include "Library.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>

bool Library::compareAuthors(Book book1, Book book2)
{
    return book1.getAuthor() < book2.getAuthor();
}

bool Library::compareBooks(Book book1, Book book2)
{
    return book1.getBook() < book2.getBook();
}

void Library::readFile(std::string filename)
{
    std::fstream newfile;
    newfile.open(filename, std::ios::in);
    if (newfile.is_open()) {
        std::string line;
        while (getline(newfile, line)) {
            std::stringstream ss(line);
            std::string author, book, text;
            getline(ss, author, ';');
            getline(ss, book, ';');
            getline(ss, text, ';');

            Book newBook(author, book, text);
            bookList.push_back(newBook);
        }

        newfile.close();
    }
}

void Library::printBookDetails()
{
    for (auto book : bookList) {
        std::cout << book.getAuthor() << ", " << book.getBook() << ", " << book.getText() << std::endl;
    }
    std::cout << std::endl;
}

void Library::sortByAuthor()
{
    std::sort(bookList.begin(), bookList.end(), compareAuthors);
}

void Library::sortByBook()
{
    std::sort(bookList.begin(), bookList.end(), compareBooks);
}

void Library::printSortedByAuthor()
{
    sortByAuthor();
    printBookDetails();
}

void Library::printSortedByBook()
{
    sortByBook();
    printBookDetails();
}

void Library::printGroupedByAuthor()
{
    sortByAuthor();
    std::string lastAuthor = "";
    for (auto book : bookList) {
        if (book.getAuthor() != lastAuthor) {
            std::cout << book.getAuthor() << std::endl;
        }
        std::cout << "\t" << book.getBook() << ", " << book.getText() << std::endl;
        lastAuthor = book.getAuthor();
    }
    std::cout << std::endl;
}