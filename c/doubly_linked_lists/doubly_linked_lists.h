/**
 * @file doubly_linked_lists.h
 * @author Rohit Sardessai
 * @brief Header file for circular doubly linked lists implementation in c
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
 * @brief Initialise a new node and set the value.
 *
 * @param value Value to be set to the node
 * @return Returns the new node
 */
node_t *list_init(int value);

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
 * @brief Returns the number of elements present in the linked list
 *
 * @param head Pointer to the list head
 * @return Returns the number of elements in the linked list
 */
int list_size(node_t *head);

/**
 * @brief Returns the value of the element at the given index in the list
 *
 * @param head Pointer to the list head
 * @param index Index of the element
 * @return Returns the value at the given index
 */
int list_value_at(node_t *head, int index);

/**
 * @brief Removes the node at the given address. If the head node needs to be removed then the head is set to the next node.
 *          If there is only one element in the noe then the head pointer is set to NULL.
 *
 * @param head Pointer to the linked list head pointer
 * @param node Pointer to the node to be deleted
 * @return Returns the value of the node that has been deleted
 */
int _list_erase_node_addr(node_t **head, node_t *node);

/**
 * @brief Remove the first node in the list
 *
 * @param head Pointer to the linked list head pointer
 * @return Returns the value of the node that has been removed
 */
int list_pop_front(node_t **head);

/**
 * @brief Removes the last node in the list
 *
 * @param head Pointer to the linked list head pointer
 * @return Returns the value of the node that has been removed
 */
int list_pop_back(node_t **head);

/**
 * @brief Removes the node at the given index
 *
 * @param head Pointer to the linked list head pointer
 * @param index Index of the node to be removed
 * @return Returns the value at the node that was removed
 */
int list_erase(node_t **head, int index);

/**
 * @brief Frees the memory used by the linked list
 *
 * @param list Pointer to the linked list head
 */
void list_destroy(node_t *list);

#endif
