/**
 * @file main.c
 * @author Rohit Sardessai
 * @brief Playing with circular doubly linked lists in c
 * @version 0.1
 * @date 2023-06-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "doubly_linked_lists.h"
#include <stdio.h>

/**
 * @brief Print the linked list
 *
 * @param list Pointer to the linked list head
 */
void print_list(node_t *list)
{
    printf("\nList:\n");
    for (node_t *tmp = list; tmp != NULL; tmp = tmp->next) {
        printf("%i ", tmp->value);
        if (tmp->next == list) {
            break;
        }
    }
    printf("\n");
}

/**
 * @brief Print the linked list in reverse order
 *
 * @param list Pointer to the linked list head
 */
void print_list_reverse(node_t *list)
{
    printf("\nList in reverse:\n");
    for (node_t *tmp = list->prev; tmp != NULL; tmp = tmp->prev) {
        printf("%i ", tmp->value);
        if (tmp == list) {
            break;
        }
    }
    printf("\n");
}

int main()
{
    node_t *head = list_init(10);

    print_list(head);

    list_push_front(&head, 20);

    list_push_back(&head, 4);
    list_push_back(&head, 5);
    list_push_back(&head, 6);

    print_list(head);
    print_list_reverse(head);

    list_destroy(head);
    return 0;
}