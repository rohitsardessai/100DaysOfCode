#include "hash_table.h"
#include <stdlib.h>
#include <string.h>

hash_table_t *ht_new()
{
    hash_table_t *ht = malloc(sizeof(hash_table_t));
    if (ht == NULL) {
        return NULL;
    }

    ht->size = 53; // fixed size for now
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item_t)); // fills the allocated memory with NULL bytes

    return ht;
}

static ht_item_t *ht_new_item(const char *k, const char *v)
{
    ht_item_t *ht_item = malloc(sizeof(ht_item_t));
    if (ht_item == NULL) {
        return NULL;
    }

    ht_item->key = strdup(k);
    ht_item->value = strdup(v);

    return ht_item;
}

static void ht_del_item(ht_item_t *item)
{
    free(item->key);
    free(item->value);
    free(item);
}

void ht_del_hash_table(hash_table_t *ht)
{
    if (ht == NULL) {
        return;
    }

    for (int i = 0; i < ht->size; i++) {
        ht_item_t *item = ht->items[i];
        if (item != NULL) {
            ht_del_item(item);
        }
    }
    free(ht->items);
    free(ht);
}