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
void add(struct list *l,int value) {
    struct node **curr = &l->head;
    while(*curr != NULL)
    {

        curr = &((*curr)->_next);
    
    }
    *curr = newNode(value,NULL);
    ++(l->size);
}
struct node* newNode(int value, struct node *next) {
    struct node *n = malloc(sizeof(struct node));
    n->data = value;
    n->_next = next;
    return n;
}
struct node **find(struct list *l,int value)
{
        struct node **curr = &l->head;
        while(*curr != NULL)
        {
            if((*curr)->data == value){
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


void printList(struct list *l)
{
    if(l == NULL || l->head == NULL) return;

    struct node *curr = l->head;
    while(curr != NULL)
    {
        printf("%d->",curr->data);
        curr = curr->_next;
    }
    printf("|\n");
}