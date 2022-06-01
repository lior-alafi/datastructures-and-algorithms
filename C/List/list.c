// 
#include "List.h"
#include <stdio.h>

struct list* init()
{
    struct list *l = malloc(sizeof(struct list));
    l->head = NULL;
    l->size = 0;
    return l;
}

void add(struct list *l,void* value) {
    l->head = newNode(value,l->head);
    ++(l->size);
}

void addToEnd(struct list *l,void* value) {
    struct node **curr = &l->head;
    while(*curr != NULL)
    {

        curr = &((*curr)->_next);
    
    }
    *curr = newNode(value,NULL);
    ++(l->size);
}
struct node* newNode(void* value, struct node *next) {
    struct node *n = malloc(sizeof(struct node));
    n->data = value;
    n->_next = next;
    return n;
}
struct node **find(struct list *l,void* value,int (*compar)(const void* lhs,const void* rhs))
{
        struct node **curr = &l->head;
        while(*curr != NULL)
        {
            if(!compar((*curr)->data,value)){
                return curr;
            }
            curr = &((*curr)->_next);           
        }


        return NULL;

}
void removeNode(struct list *l,struct node **n){
    if(n == NULL || *n == NULL) return;
    struct node *tmp = *n;
    *n = ((*n)->_next);
    free(tmp);
    --l->size;
}


void printList(struct list *l,char *(*toStr)(const void *x))
{
    if(l == NULL || l->head == NULL) return;

    struct node *curr = l->head;
    while(curr != NULL)
    {
        char *buff = toStr(curr->data);
        printf("%s->",buff);
        free(buff);
        curr = curr->_next;
    }
    printf("|\n");
}

void reverse(struct list *l)
{
    if(l == NULL)
    {
        return;
    }
    struct node *prev=NULL,
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
        struct node *next = curr->_next;
        curr->_next = prev;
        prev = curr;
        curr = next;
    }
    l->head = prev;
}


void clearList(struct list *l,int deleteValues)
{
    if(!l) 
    {
        return;
    }

    while (l->head != NULL)
    {
        struct node *tmp = l->head;
        l->head = l->head->_next;
        if(deleteValues)
        {
            free(tmp->data);
        }
        free(tmp);
    }
    
}