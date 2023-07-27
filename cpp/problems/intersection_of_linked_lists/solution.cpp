/**
 * @file solution.cpp
 * @author Rohit Sardessai
 * @brief Find the intersection of two linked lists. Problem from GeeksForGeeks. More details below.
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

Node::Node(int val)
{
    data = val;
    next = nullptr;
}

void Solution::node_add(Node **head, int data)
{
    Node *newNode = new Node(data);

    Node *tmp = *head;

    if (tmp == nullptr) {
        *head = newNode;
        return;
    }
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

Node *Solution::findIntersection(Node *head1, Node *head2)
{
    std::unordered_set<int> unionSet;
    Node *intersectionSet = nullptr;

    Node *tmp = head2;
    while (tmp != nullptr) {
        unionSet.insert(tmp->data);
        tmp = tmp->next;
    }

    tmp = head1;

    while (tmp != nullptr) {
        if (unionSet.find(tmp->data) != unionSet.end()) {
            node_add(&intersectionSet, tmp->data);
        } else {
            unionSet.insert(tmp->data);
        }
        tmp = tmp->next;
    }

    return intersectionSet;
}
