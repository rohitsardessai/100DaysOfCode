/**
 * @file doubly_linked_lists.c
 * @author Rohit Sardessai
 * @brief Doubly linked list implementation in c
 * @version 0.1
 * @date 2023-06-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "doubly_linked_lists.h"

node_t *new_node()
{
    node_t *new_node = malloc(sizeof(node_t));

    if (new_node == NULL) {
        printf("\nUnable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void list_push_front(node_t **head, int value)
{
    node_t *n = new_node();
    n->value = value;
    n->prev = NULL;
    n->next = *head;

    *head = n;
}

void list_destroy(node_t *list)
{
    while (list != NULL) {
        node_t *tmp = list->next;
        free(list);
        list = tmp;
    }
}