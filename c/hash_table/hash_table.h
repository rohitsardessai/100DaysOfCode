
/*
This is a reimplementation of hash tables originally made by jamesroutley on GitHub. Link: https://github.com/jamesroutley/write-a-hash-table
*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct {
    char *key;
    char *value;
} ht_item_t;

typedef struct {
    int size;
    int count;
    ht_item_t **items;
} hash_table_t;

/**
 * @brief Create a new empty hash table
 *
 * @return hash_table_t*
 */
hash_table_t *ht_new();

/**
 * @brief Create a new hash table item (key value pair)
 *
 * @param k Key of the item (string)
 * @param v Value associated with the given key (string)
 * @return Returns a pointer to the newly created item
 */
static ht_item_t *ht_new_item(const char *k, const char *v);

/**
 * @brief Deletes an items and frees the memory used
 *
 * @param item Pointer to the item to be deleted
 */
static void ht_del_item(ht_item_t *item);

/**
 * @brief Deletes a hash table and all the elements in it. Frees up all the memory used by the hash table and it's elements
 *
 * @param ht Pointer to the hash table
 */
void ht_del_hash_table(hash_table_t *ht);

#endif