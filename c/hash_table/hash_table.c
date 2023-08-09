#include "hash_table.h"
#include "prime.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

static ht_item_t HT_DELETED_ITEM = {NULL, NULL};

hash_table_t *ht_new()
{
    return ht_new_sized(HT_INITIAL_BASE_SIZE);
}

static hash_table_t *ht_new_sized(const int base_size)
{
    hash_table_t *ht = malloc(sizeof(hash_table_t));
    if (ht == NULL) {
        return NULL;
    }

    ht->base_size = base_size;
    ht->size = next_prime(ht->base_size);
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item_t *)); // fills the allocated memory with NULL bytes

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
        if (item != NULL && item != &HT_DELETED_ITEM) {
            ht_del_item(item);
        }
    }
    free(ht->items);
    free(ht);
}

static int ht_hash(const char *str, const int prime, const int no_of_buckets)
{
    long hash = 0;
    int str_len = strlen(str);

    for (int i = 0; i < str_len; i++) {
        hash += (long)pow(prime, (str_len - (i + 1))) * str[i];
        hash = hash % no_of_buckets;
    }

    return (int)hash;
}

static int ht_get_hash(const char *str, const int no_of_buckets, const int attempt)
{
    const int ht_hash_a = ht_hash(str, HT_PRIME_1, no_of_buckets);
    const int ht_hash_b = ht_hash(str, HT_PRIME_2, no_of_buckets);

    /**
     * This is a technique called open addressing with double hashing.
     * If there is a collision, the index to be used after i collisions is:
     *
     * index = hash_a(string) + i * hash_b(string) % no_of_buckets
     *
     * If no collisions have occurred, (i=0), then index is hash_a(string).
     * A problem that can occur is that hash_b returns 0. This will cause all subsequent
     * hashes to be 0. This can be solved by adding 1 to hash_b. Therefore:
     *
     * index = (hash_a(string) + i * (hash_b(string) + 1)) % no_of_buckets
     */

    return (ht_hash_a + (attempt * (ht_hash_b + 1))) % no_of_buckets;
}

void ht_insert(hash_table_t *ht, const char *key, const char *value)
{
    if (ht == NULL || key == NULL || value == NULL) {
        return;
    }

    ht_item_t *item = ht_new_item(key, value);

    int index = ht_get_hash(item->key, ht->size, 0);
    int attempt = 1;
    while (ht->items[index] != NULL && ht->items[index] != &HT_DELETED_ITEM) {
        if (strcmp(ht->items[index]->key, key) == 0) {
            ht_del_item(ht->items[index]);
            ht->count--;
            break;
        }
        index = ht_get_hash(item->key, ht->size, attempt);
        attempt++;
        if (attempt > ht->size) {
            ht_del_item(item);
            return;
        }
    }

    ht->items[index] = item;
    ht->count++;
}

char *ht_search(hash_table_t *ht, const char *key)
{
    if (ht == NULL || key == NULL) {
        return NULL;
    }

    int index = ht_get_hash(key, ht->size, 0);

    int attempt = 1;

    while (ht->items[index] != NULL) {
        if (ht->items[index] != &HT_DELETED_ITEM) {
            if (strcmp(ht->items[index]->key, key) == 0) {
                return ht->items[index]->value;
            }
        }
        index = ht_get_hash(key, ht->size, attempt);
        attempt++;
        if (attempt > ht->size) {
            break;
        }
    }

    return NULL;
}

void ht_delete(hash_table_t *ht, const char *key)
{
    if (ht == NULL || key == NULL) {
        return;
    }

    int index = ht_get_hash(key, ht->size, 0);

    int attempt = 1;
    while (ht->items[index] != NULL) {
        if (ht->items[index] != &HT_DELETED_ITEM) {
            if (strcmp(ht->items[index]->key, key) == 0) {
                ht_del_item(ht->items[index]);
                ht->items[index] = &HT_DELETED_ITEM;
                ht->count--;
                return;
            }
        }
        index = ht_get_hash(key, ht->size, attempt);
        attempt++;
        if (attempt > ht->size) {
            return;
        }
    }
}