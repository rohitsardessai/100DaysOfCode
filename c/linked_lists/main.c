#include "linked_lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Print the linked list
 *
 * @param list Pointer to the linked list head
 */
void print_list(node_t *list)
{
    printf("\nList:\n");
    for (node_t *tmp = list; tmp != NULL; tmp = tmp->next) {
        printf("%i ", tmp->data);
    }
    printf("\n");
}

int main()
{
    printf("\nLinked Lists\n\n");

    node_t *list = NULL;

    int no_of_nodes;
    printf("How many nodes do you want?\n");
    scanf("%i", &no_of_nodes);

    for (int i = no_of_nodes; i > 0; i--) {
        list_push_front(&list, i);
    }

    print_list(list);

    list_destroy(list);

    printf("Done\n\n");

    return 0;
}