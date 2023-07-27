#ifndef SOLUTION_H
#define SOLUTION_H

#include <unordered_set>

struct Node {
    int data;
    Node *next;
    Node(int val);
};

class Solution
{
public:
    void node_add(Node **head, int data);
    Node *findIntersection(Node *head1, Node *head2);
};

#endif
