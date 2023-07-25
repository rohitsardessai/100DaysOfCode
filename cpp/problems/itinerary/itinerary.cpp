/**
 * @file itinerary.cpp
 * @author Rohit Sardessai
 * @brief Problem involving hash tables taken from GeeksForGeeks. More info below.
 * @version 0.1
 * @date 2023-07-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
#include <unordered_map>

/*
Problem taken from: https://www.geeksforgeeks.org/find-itinerary-from-a-given-list-of-tickets/
Given a list of tickets, find itinerary in order using the given list.

Example:

Input:
"Chennai" -> "Banglore"
"Bombay" -> "Delhi"
"Goa"    -> "Chennai"
"Delhi"  -> "Goa"

Output:
Bombay->Delhi, Delhi->Goa, Goa->Chennai, Chennai->Banglore,
It may be assumed that the input list of tickets is not cyclic and there is one ticket from every city except the final destination.
*/

std::string findItinerary(const std::unordered_map<std::string, std::string> &tickets)
{
    std::unordered_map<std::string, std::string> reversed_tickets;

    for (const auto &place : tickets) {
        reversed_tickets.insert(std::pair<std::string, std::string>(place.second, place.first));
    }

    std::string startDestination;

    for (const auto &place : tickets) {
        if (reversed_tickets.find(place.first) == reversed_tickets.end()) {
            startDestination = place.first;
            break;
        }
    }

    std::string itinerary;
    std::string nextDestination = startDestination;
    while (tickets.find(nextDestination) != tickets.end()) {
        itinerary += nextDestination;
        itinerary += " -> ";
        itinerary += tickets.at(nextDestination);
        itinerary += ", ";
        nextDestination = tickets.at(nextDestination);
    }
    itinerary.pop_back(); // remove the last comma, space
    itinerary.pop_back();

    return itinerary;
}

int main()
{
    std::unordered_map<std::string, std::string> tickets = {
        {"Chennai", "Bangalore"},
        {"Bombay", "Delhi"},
        {"Goa", "Chennai"},
        {"Delhi", "Goa"}};

    std::string itinerary = findItinerary(tickets);

    std::cout << "Itinerary:" << std::endl;
    std::cout << itinerary << std::endl
              << std::endl;

    return 0;
}