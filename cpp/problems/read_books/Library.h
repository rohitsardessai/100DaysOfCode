#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>

class Library
{
    std::vector<Book> bookList;

    static bool compareAuthors(Book book1, Book book2);
    static bool compareBooks(Book book1, Book book2);

public:
    void readFile(std::string filename);
    void printBookDetails();
    void sortByAuthor();
    void sortByBook();
    void printSortedByAuthor();
    void printSortedByBook();
    void printGroupedByAuthor();
};

#endif