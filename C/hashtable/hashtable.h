#include "../List/List.h"

const int MAX_HASH_TABLE_SIZE = 500;


struct hashtable_t {
    struct list l[MAX_HASH_TABLE_SIZE];
};

void hashInsert(struct hashtable_t *tbl, const char *key,void *data);