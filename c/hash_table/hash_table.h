
/*
This is a reimplementation of hash tables originally made by jamesroutley on GitHub. Link: https://github.com/jamesroutley/write-a-hash-table
*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stddef.h>

#define HT_PRIME_1 151
#define HT_PRIME_2 173

typedef struct {
    char *key;
    char *value;
} ht_item_t;

typedef struct {
    int size;
    int count;
    ht_item_t **items;
} hash_table_t;

static ht_item_t HT_DELETED_ITEM = {NULL, NULL};

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

/**
 * @brief Take a string as its input and return a number between 0 and no_of_buckets, our desired bucket array length.
 *
 * @param str String to be hashed
 * @param prime A prime number larger than the size of the alphabet
 * @param no_of_buckets The number of buckets available in the hash table
 * @return Returns an integer between 0 and no_of_buckets
 */
static int ht_hash(const char *str, const int prime, const int no_of_buckets);

/**
 * @brief Returns an index between 0 and no_of_buckets. The hash is calculated based
 *        on the number of attempts.
 *
 * @param str The key to be hashed (string)
 * @param no_of_buckets The number of buckets available in the hash table
 * @param attempt The attempt number to calculate the hash
 * @return Returns an index between 0 and no_of_buckets
 */
static int ht_get_hash(const char *str, const int no_of_buckets, const int attempt);

/**
 * @brief Inserts a key value pair in the hash table
 *
 * @param ht Pointer to the hash table
 * @param key Key to be inserted (string)
 * @param value Value to be inserted (string)
 */
void ht_insert(hash_table_t *ht, const char *key, const char *value);

/**
 * @brief Searches the hash table for a given key, If the key is found, it returns
 *        the value associated with that key. If the key does not exist in the hash
 *        table, it returns NULL.
 *
 * @param ht Pointer to the hash table
 * @param key Key to be searched for (string)
 * @return Returns a pointer to the value associated with that key (char *)
 */
char *ht_search(hash_table_t *ht, const char *key);

/**
 * @brief Deletes an item from the hash table
 *
 * @param ht Pointer to the hash table
 * @param key Key of the key value pair to be deleted
 */
void ht_delete(hash_table_t *ht, const char *key);

#endif