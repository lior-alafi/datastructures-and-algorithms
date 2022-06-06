
#ifndef HASH_TABLE
#define HASH_TABLE

#include "../List/List.h"


#define MAX_HASH_TABLE_SIZE 10


struct hashChain_t {
    char *key;
    void *value;
};
struct hashtable_t {
    struct list_t l[MAX_HASH_TABLE_SIZE];
};


struct hashtable_t* hashInit(struct hashtable_t *tbl);
void hashInsert(struct hashtable_t *tbl, const char *key,void *data);
void * hashRemove(struct hashtable_t *tbl, const char *key,int deleteData);
void* hashFind(struct hashtable_t *tbl, const char *key);
#endif