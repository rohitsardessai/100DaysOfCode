/**
 * @file doubly_linked_lists.h
 * @author Rohit Sardessai
 * @brief Header file for doubly linked list implementation in c
 * @version 0.1
 * @date 2023-06-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DOUBLY_LINKED_LISTS_H
#define DOUBLY_LINKED_LISTS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Struct to define node. Value is the element at that node.
 *        *next is a pointer to the next node, *prev is a pointer to the previous node.
 *
 */
typedef struct node {
    int value;
    struct node *next;
    struct node *prev;
} node_t;

/**
 * @brief Creates a new node and sets the pointer to NULL
 *
 * @return Returns the newly created node struct
 */
node_t *new_node();

/**
 * @brief Add a node at the beginning of the linked list
 *
 * @param head Pointer to the linked list head pointer
 * @param value Value to be inserted
 */
void list_push_front(node_t **head, int value);

/**
 * @brief Frees the memory used by the linked list
 *
 * @param list Pointer to the linked list head
 */
void list_destroy(node_t *list);

#endif
