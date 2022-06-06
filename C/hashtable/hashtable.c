#include "hashtable.h"
#include <string.h>
#include <stdlib.h>
#include <string.h>

struct hashChain_t {
    const char *key;
    void *value;
};
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
    strncpy(chain->key,key,strlen(key));

    return chain;
}

void hashInsert(struct hashtable_t *tbl,const char *key,void *data)
{
    if(tbl == NULL)
    {
        tbl = malloc(sizeof(struct hashtable_t));
        if(!tbl)
        {
            return NULL;
        }
    }

    add(&(tbl->l[hashFunc(key)]),makeChainElement(key,data));
}

int hashcompare(const void *lhs,const void *rhs)
{
    return strncmp(((struct hashChain_t*)lhs)->key,rhs);
}


struct node ** hashFindAux(struct hashtable_t *tbl, const char *key)
{
   if (tbl == NULL || strlen(key) == 0 )
    {
        return NULL;
    }

    int idx = hashFunc(key);
    struct node **n = find(&(tbl->l[idx]),key,hashcompare);
    if(n == NULL || *n == NULL)
    {
        return NULL;
    }

    return n;
}
void* hashFind(struct hashtable_t *tbl, const char *key)
{
  
    struct node **n = hashFindAux(tbl,key);
    if(n == NULL || *n == NULL || (*n)->data == NULL)
    {   
       return NULL;
    }

    return ((struct hashChain_t*)((*n)->data))->value;
}

void * hashRemove(struct hashtable_t *tbl, const char *key,int deleteData)
{
    struct node **n = hashFindAux(tbl,key);
    if(n == NULL || *n == NULL || (*n)->data == NULL)
    {   
       return NULL;
    }
    struct hashChain_t *tmp =(*n)->data;
    free(tmp->key);
    void removeNode(struct list *l,struct node **n);
    void* data= tmp->value;
    free(tmp);
    if(!deleteData)
    { 
        return data;
    }

    free(data);
    return NULL;
}