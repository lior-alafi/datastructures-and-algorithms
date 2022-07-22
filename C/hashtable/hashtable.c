#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"


int hashFunc(const char *key)
{
    int hash = 0;
    for (size_t i = 0; i < strlen(key); i++)
    {
        hash = (hash + key[i]) % MAX_HASH_TABLE_SIZE;
    }
    return hash;
}

struct hashChain_t *makeChainElement(const char* key, void *value)
{
    struct hashChain_t *chain = malloc(sizeof(struct hashChain_t));
    if (!chain)
    {
        return NULL;
    }
    chain->value = value;
    chain->key = calloc(sizeof(char),strlen(key)+1);
    strncpy(chain->key,key,strlen(key)+1);

    return chain;
}
struct hashtable_t* hashInit(struct hashtable_t *tbl)
{
    if(tbl == NULL)
    {
       
            return NULL;
        // }
    }

    for (int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
    {
        tbl->l[i].head = NULL;
        tbl->l[i].size = 0;
    }

    return tbl;
    
}
void hashInsert(struct hashtable_t *tbl,const char *key,void *data)
{
    if(tbl == NULL)
    {
        tbl = malloc(sizeof(struct hashtable_t));
        if(!tbl)
        {
            return;
        }
    }

    add(&(tbl->l[hashFunc(key)]),makeChainElement(key,data));
}

int hashcompare(const void *lhs,const void *rhs)
{
    return strcmp(((struct hashChain_t*)lhs)->key,rhs);
}


struct node_t ** hashFindAux(struct hashtable_t *tbl, const char *key)
{
   if (tbl == NULL || strlen(key) == 0 )
    {
        return NULL;
    }

    int idx = hashFunc(key);
    struct node_t **n = find(&(tbl->l[idx]),key,hashcompare);
    if(n == NULL || *n == NULL)
    {
        return NULL;
    }

    return n;
}
void* hashFind(struct hashtable_t *tbl, const char *key)
{
  
    struct node_t **n = hashFindAux(tbl,key);
    if(n == NULL || *n == NULL || (*n)->data == NULL)
    {   
       return NULL;
    }

    return ((struct hashChain_t*)((*n)->data))->value;
}

void * hashRemove(struct hashtable_t *tbl, const char *key,void (*deleteF)(void* data))
{
    struct node_t **n = hashFindAux(tbl,key);
    if(n == NULL || *n == NULL || (*n)->data == NULL)
    {   
       return NULL;
    }
    struct hashChain_t *tmp =(*n)->data;
    free(tmp->key);
    void* data= tmp->value;
    removeNode(tbl->l,n,deleteF);
    if(deleteF == NULL)
    { 
        return data;
    }

    deleteF(data);
    return NULL;
}