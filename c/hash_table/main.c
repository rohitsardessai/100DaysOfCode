#include "hash_table.h"

int main()
{
    hash_table_t *my_ht = ht_new();
    ht_del_hash_table(my_ht);
    return 0;
}