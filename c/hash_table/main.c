#include "hash_table.h"
#include <stdio.h>

int main()
{
    printf("START\n");

    hash_table_t *my_ht = ht_new();
    ht_insert(my_ht, "hello", "world");
    char *value = ht_search(my_ht, "hello");
    if (value != NULL) {
        printf("value = %s\n", value);
    } else {
        printf("The key does not exist in the hash table.");
    }

    ht_insert(my_ht, "dog", "bark");
    ht_insert(my_ht, "dog", "mews");
    ht_delete(my_ht, "dog");
    value = NULL;
    value = ht_search(my_ht, "dog");
    if (value != NULL) {
        printf("value = %s\n", value);
    } else {
        printf("The key does not exist in the hash table.");
    }

    ht_del_hash_table(my_ht);

    printf("\nEND\n");

    return 0;
}