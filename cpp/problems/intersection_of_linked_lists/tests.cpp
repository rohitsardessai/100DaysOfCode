/**
 * @file tests.cpp
 * @author ChatGPT
 * @brief Test cases for the solution of the intersection of linked lists problem. The test cases are qritten by ChatGPT.
 * @version 0.1
 * @date 2023-07-28
 *
 * @copyright Copyright (c) 2023
 *
 */

/*
Taken from: https://practice.geeksforgeeks.org/problems/intersection-of-two-linked-list/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

Given two linked lists, the task is to complete the function findIntersection(), that returns the intersection of two linked lists.
Each of the two linked list contains distinct node values.

Example 1:

Input:
LinkedList1: 9->6->4->2->3->8
LinkedList2: 1->2->8->6

Output: 6 2 8

Your Task:
You task is to complete the function findIntersection() which takes the heads of the 2 input linked lists as parameter and returns the head of intersection list.
Returned list will be automatically printed by driver code.
Note: The order of nodes in this list should be same as the order in which those particular nodes appear in input list 1.

Constraints:
1 <= n,m <= 104

Expected time complexity: O(m+n)
Expected auxiliary space: O(m+n)
*/

#include "solution.h"
#include <cassert>
#include <iostream>

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

bool compareLists(Node *list1, Node *list2)
{
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data != list2->data) {
            return false;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    return list1 == nullptr && list2 == nullptr;
}

void runTestCases()
{
    Solution solution;

    // Test Case 1: Two lists have an intersection
    Node *list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);
    list1->next->next->next = new Node(4);
    list1->next->next->next->next = new Node(5);
    Node *intersection = new Node(6);
    intersection->next = new Node(7);
    list1->next->next->next->next->next = intersection;
    Node *list2 = new Node(8);
    list2->next = intersection;

    Node *expectedIntersection = new Node(6);
    expectedIntersection->next = new Node(7);

    Node *intersectionHead = solution.findIntersection(list1, list2);

    assert(compareLists(intersectionHead, expectedIntersection));
    std::cout << "Test Case 1 Passed!" << std::endl;

    // // Clean up memory (delete the allocated nodes)
    // Node *temp;
    // while (list1 != nullptr) {
    //     temp = list1;
    //     list1 = list1->next;
    //     delete temp;
    // }

    // while (list2 != nullptr) {
    //     temp = list2;
    //     list2 = list2->next;
    //     delete temp;
    // }

    // while (expectedIntersection != nullptr) {
    //     temp = expectedIntersection;
    //     expectedIntersection = expectedIntersection->next;
    //     delete temp;
    // }

    // Test Case 2: Two lists do not have an intersection
    Node *list3 = new Node(11);
    list3->next = new Node(12);
    list3->next->next = new Node(13);
    list3->next->next->next = new Node(14);
    list3->next->next->next->next = new Node(15);
    Node *list4 = new Node(21);
    list4->next = new Node(22);
    list4->next->next = new Node(23);
    list4->next->next->next = new Node(24);
    list4->next->next->next->next = new Node(25);

    Node *intersectionHead2 = solution.findIntersection(list3, list4);

    assert(intersectionHead2 == nullptr);
    std::cout << "Test Case 2 Passed!" << std::endl;

    // Clean up memory (delete the allocated nodes)
    Node *temp;
    while (list1 != nullptr) {
        temp = list1;
        list1 = list1->next;
        delete temp;
    }

    while (list2 != nullptr) {
        temp = list2;
        list2 = list2->next;
        delete temp;
    }

    while (expectedIntersection != nullptr) {
        temp = expectedIntersection;
        expectedIntersection = expectedIntersection->next;
        delete temp;
    }

    // Clean up memory (delete the allocated nodes)
    while (list3 != nullptr) {
        temp = list3;
        list3 = list3->next;
        delete temp;
    }

    while (list4 != nullptr) {
        temp = list4;
        list4 = list4->next;
        delete temp;
    }

    std::cout << "All test cases passed!" << std::endl;
}

int main()
{
    runTestCases();
    return 0;
}
