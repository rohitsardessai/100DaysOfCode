/**
 * @file linked_lists.h
 * @author Rohit Sardessai
 * @brief Linked list implementation in c
 * @version 0.1
 * @date 2023-06-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Node struct. This holds the data and a pointer to the next node.
 *
 */
typedef struct node {
    int data;
    struct node *next;
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
 * @brief Add a node at the end of the list
 *
 * @param head Pointer to the linked list head pointer
 * @param value Value to be inserted
 */
void list_push_back(node_t **head, int value);

/**
 * @brief Returns the value at a given index
 *
 * @param head Pointer to the linked list head pointer
 * @param index Index of the element
 * @return Returns the value at the specified index
 */
int list_value_at(node_t **head, int index);

/**
 * @brief Returns the number of nodes present in the linked list
 *
 * @param head Pointer to the linked list head pointer
 * @return Returns the number of nodes present in the linked list
 */
int list_size(node_t **head);

/**
 * @brief Inserts a node at the given index in the list
 *
 * @param head Pointer to the linked list head pointer
 * @param index Index at which to insert the new node
 * @param value Value to be inserted
 */
void list_insert(node_t **head, int index, int value);

/**
 * @brief Deletes the node at the given index
 *
 * @param head Pointer to the linked list head pointer
 * @param index Index of the node to be deleted
 */
void list_erase(node_t **head, int index);

/**
 * @brief Reverses the linked list. Points head to the last element and changed the next pointer of each node to point to the previous node.
 *
 * @param head
 */
void list_reverse(node_t **head);

/**
 * @brief Frees the memory used by the linked list
 *
 * @param list Pointer to the linked list head
 */
void list_destroy(node_t *list);

#endif