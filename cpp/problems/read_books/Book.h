#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
    std::string author;
    std::string book;
    std::string text;

public:
    Book(std::string newAuthor, std::string newBook, std::string newText);

    std::string getAuthor();
    std::string getBook();
    std::string getText();
};

#endif