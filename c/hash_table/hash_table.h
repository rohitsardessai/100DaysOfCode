
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

hash_table_t *ht_new();

static ht_item_t *ht_new_item(const char *k, const char *v);

static void ht_del_item(ht_item_t *item);

void ht_del_hash_table(hash_table_t *ht);

#endif