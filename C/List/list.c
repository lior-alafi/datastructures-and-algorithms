// 
#include "List.h"
#include <stdio.h>

struct list_t* init()
{
    struct list_t *l = malloc(sizeof(struct list_t));
    l->head = NULL;
    l->size = 0;
    return l;
}

void add(struct list_t *l,void* value) {
    l->head = newNode(value,l->head);
    ++(l->size);
}

void addToEnd(struct list_t *l,void* value) {
    struct node_t **curr = &l->head;
    while(*curr != NULL)
    {

        curr = &((*curr)->_next);
    
    }
    *curr = newNode(value,NULL);
    ++(l->size);
}
struct node_t* newNode(void* value, struct node_t *next) {
    struct node_t *n = malloc(sizeof(struct node_t));
    n->data = value;
    n->_next = next;
    return n;
}
struct node_t **find(struct list_t *l,void* value,int (*compar)(const void* lhs,const void* rhs))
{
        struct node_t **curr = &l->head;
        while(*curr != NULL)
        {
            if(!compar((*curr)->data,value)){
                return curr;
            }
            curr = &((*curr)->_next);           
        }


        return NULL;

}
void removeNode(struct list_t *l,struct node_t **n,void (*deleteF)(void* data)){
    if(n == NULL || *n == NULL) return;
    struct node_t *tmp = *n;
    if (deleteF != NULL) {
        deleteF(tmp->data);
    }
    *n = ((*n)->_next);
    free(tmp);
    --l->size;
}


void printList(struct list_t *l,char *(*toStr)(const void *x))
{
    if(l == NULL || l->head == NULL) return;

    struct node_t *curr = l->head;
    while(curr != NULL)
    {
        char *buff = toStr(curr->data);
        printf("%s->",buff);
        free(buff);
        curr = curr->_next;
    }
    printf("|\n");
}

void reverse(struct list_t *l)
{
    if(l == NULL)
    {
        return;
    }
    struct node_t *prev=NULL,
                *curr = l->head;
                // *next = NULL;
    while(curr != NULL)
    {
        /*
            just reverse the current each time, no need for next->next (if it even exists)
            i.e:
            1->|
          p c  n  => c->p => p=c,c =n
        */
        struct node_t *next = curr->_next;
        curr->_next = prev;
        prev = curr;
        curr = next;
    }
    l->head = prev;
}


void clearList(struct list_t *l,void (*deleteF)(void* data))
{
    if(!l) 
    {
        return;
    }

    while (l->head != NULL)
    {
        struct node_t *tmp = l->head;
        l->head = l->head->_next;
        if(deleteF != NULL)
        {
            deleteF(tmp->data);
        }
        free(tmp);
        --(l->size);
    }
    
}