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
    }
    printf("\n");
}

int main()
{
    return 0;
}