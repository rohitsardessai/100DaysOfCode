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
    return n;
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

void list_push_back(node_t **head, int value)
{
    node_t *list_head = *head;
    node_t *n = new_node();
    n->value = value;
    n->next = *head;
    n->prev = list_head->prev;

    list_head->prev->next = n;
    list_head->prev = n;
}

int list_size(node_t *head)
{
    node_t *tmp = head;
    int no_of_nodes = 0;
    do {
        if (tmp == NULL) {
            break;
        }
        no_of_nodes++;
        tmp = tmp->next;
    } while ((tmp != head));

    return no_of_nodes;
}

int list_value_at(node_t *head, int index)
{
    node_t *tmp = head;
    int i = 0;
    do {
        if (tmp == NULL) {
            exit(EXIT_FAILURE);
        }
        if (i == index) {
            return tmp->value;
        }
        tmp = tmp->next;
        i++;
    } while ((tmp != head));
    exit(EXIT_FAILURE);
    return -1;
}

int _list_erase_node_addr(node_t **head, node_t *node)
{
    if (node == NULL || *head == NULL) {
        exit(EXIT_FAILURE);
    }

    int value = node->value;

    node->prev->next = node->next;
    node->next->prev = node->prev;

    if (node == *head) {
        if ((*head)->next == *head) {
            *head = NULL;
        } else {
            *head = (*head)->next;
        }
    }

    free(node);

    return value;
}

int list_pop_front(node_t **head)
{
    return _list_erase_node_addr(head, *head);
}

int list_pop_back(node_t **head)
{
    return _list_erase_node_addr(head, (*head)->prev);
}

int list_erase(node_t **head, int index)
{
    node_t *tmp = *head;
    int i = 0;
    do {
        if (tmp == NULL) {
            exit(EXIT_FAILURE);
        }
        if (i == index) {
            return _list_erase_node_addr(head, tmp);
        }
        tmp = tmp->next;
        i++;
    } while ((tmp != *head));
    exit(EXIT_FAILURE);
    return -1;
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