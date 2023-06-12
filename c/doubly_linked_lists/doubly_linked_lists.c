/**
 * @file doubly_linked_lists.c
 * @author Rohit Sardessai
 * @brief Circular doubly linked list implementation in c
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
    new_node->next = new_node;
    new_node->prev = new_node;
    return new_node;
}

node_t *list_init(int value)
{
    node_t *n = new_node();
    n->value = value;
}

void list_push_front(node_t **head, int value)
{
    node_t *list_head = *head;
    node_t *n = new_node();
    n->value = value;
    n->prev = list_head->prev;
    n->next = *head;

    list_head->prev->next = n;

    list_head->prev = n;
    *head = n;
}

void list_destroy(node_t *head)
{
    node_t *list_head = head;
    while (head != NULL) {
        node_t *tmp = head->next;
        free(head);
        head = tmp;
        if (head == list_head) {
            break;
        }
    }
}