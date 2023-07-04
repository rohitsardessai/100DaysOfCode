/**
 * @file readBooks.cpp
 * @author Rohit Sardessai
 * @brief Read a csv file and sort the data. The full problem is stated below.
 * @version 0.1
 * @date 2023-06-25
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
Read the problem below and create a cpp program, applying object oriented
skills, and using classes to come up with a solution.

A Semicolon Separated file is provided, containing information about Authors, Book
Titles, and Text from books.

You are expected to read the data file (only once), and store the data within your
program (One Single Program). The data is then used to output three different report
formats. The purpose of the exercise to see how well you can design a Class structure
to hold the given data and effectively use it.

1. All records sorted in ascending order of Author Names.
    Sample output:
        Jane Austen, Pride and Prejudice, Text
        Jane Austen, Sense and Sensibility, Text
        Stephen King, A Brief History of Time, Text
        Virginia Woolf, The Waves, Text
2. All records sorted in ascending order of Book Title.
    Sample output:
        Stephen King, A Brief History of Time, Text
        Jane Austen, Pride and Prejudice,Text
        Jane Austen, Sense and Sensibility, Text
        Virginia Woolf, The Waves, Text
3. All Book Titles grouped by Author Name.
    Sample output:
        Jane Austen
            Pride and Prejudice
            Sense and Sensibility
        Stephen King
            A Brief History of Time
        Virginia Woolf
            The Waves

A semicolon separated data file is provided, named data.csv
*/

#include "Book.h"
#include "Library.h"
#include <iostream>

int main()
{
    Library myLibrary;

    myLibrary.readFile("data.csv");

    std::cout << "Sorted by books: " << std::endl
              << std::endl;
    myLibrary.printSortedByBook();

    std::cout << "Sorted by author: " << std::endl
              << std::endl;
    myLibrary.printSortedByAuthor();

    std::cout << "Grouped by author: " << std::endl
              << std::endl;
    myLibrary.printGroupedByAuthor();

    std::cout << std::endl;
}