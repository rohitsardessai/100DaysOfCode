#include "Book.h"

Book::Book(std::string newAuthor, std::string newBook, std::string newText)
{
    author = newAuthor;
    book = newBook;
    text = newText;
}

std::string Book::getAuthor()
{
    return author;
}

std::string Book::getBook()
{
    return book;
}

std::string Book::getText()
{
    return text;
}