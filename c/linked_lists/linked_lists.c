/**
 * @file linked_lists.c
 * @author Rohit Sardessai
 * @brief Linked list implementation in c
 * @version 0.1
 * @date 2023-06-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "linked_lists.h"

node_t *new_node()
{
    node_t *n = malloc(sizeof(node_t));
    if (n == NULL) {
        printf("\nUnable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    n->next = NULL;
    return n;
}

void list_push_front(node_t **head, int value)
{
    node_t *n = new_node();
    n->data = value;
    n->next = *head;

    *head = n;
}

void list_push_back(node_t **head, int value)
{
    node_t *n = new_node();
    n->data = value;
    n->next = NULL;

    node_t *tmp = *head;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = n;
}

int list_value_at(node_t **head, int index)
{
    node_t *tmp = *head;

    for (int i = 0; i <= index && tmp->next != NULL; i++) {
        if (i == index) {
            return tmp->data;
        }
        tmp = tmp->next;
    }

    exit(EXIT_FAILURE);
    return -1;
}

int list_size(node_t **head)
{
    if (*head == NULL) {
        return 0;
    }

    int size = 1;
    node_t *tmp = *head;

    while (tmp->next != NULL) {
        size++;
        tmp = tmp->next;
    }

    return size;
}

void list_insert(node_t **head, int index, int value)
{
    node_t *n = new_node();
    n->data = value;

    node_t *tmp = *head;

    if (index == 0) {
        list_push_front(head, value);
        return;
    }

    for (int i = 0; i <= index; i++) {
        if (i == index - 1) {
            break;
        }
        if (tmp->next == NULL) {
            exit(EXIT_FAILURE);
        }
        tmp = tmp->next;
    }

    n->next = tmp->next;
    tmp->next = n;
}

void list_erase(node_t **head, int index)
{
    node_t *tmp = *head;

    if (index == 0) {
        *head = tmp->next;
        return;
    }

    for (int i = 0; i <= index; i++) {
        if (tmp->next == NULL) {
            exit(EXIT_FAILURE);
        }
        if (i == index - 1) {
            node_t *node_to_delete = tmp->next;
            if (tmp->next->next != NULL) {
                tmp->next = tmp->next->next;
            } else {
                tmp->next == NULL;
            }
            free(node_to_delete);
            break;
        }
        tmp = tmp->next;
    }
}

void list_destroy(node_t *list)
{
    while (list != NULL) {
        node_t *tmp = list->next;
        free(list);
        list = tmp;
    }
}