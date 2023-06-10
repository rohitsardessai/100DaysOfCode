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

    list_push_front(&list, 50);

    list_push_back(&list, 100);

    list_insert(&list, 4, 22);
    list_insert(&list, 0, 21);
    list_insert(&list, 3, 23);

    print_list(list);
    list_erase(&list, 0);
    print_list(list);

    printf("Which index would you like to check?\n");
    int index_to_check = 0;
    scanf("%i", &index_to_check);
    printf("Value at index %i is %i\n", index_to_check, list_value_at(&list, index_to_check));

    printf("Linked list size = %i\n", list_size(&list));

    list_destroy(list);

    printf("Done\n\n");

    return 0;
}