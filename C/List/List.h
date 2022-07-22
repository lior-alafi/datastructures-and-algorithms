#ifndef LIST_H
#define LIST_H

#include <stdlib.h>



struct node_t {
  struct node_t *_next;
  void *data;
};


struct list_t {
 int size;
 struct node_t *head;
};



struct list_t* init();
void addToEnd(struct list_t *l,void* value);
void add(struct list_t *l,void* value);
struct node_t* newNode(void* value, struct node_t *next);
struct node_t **find(struct list_t *l,void* value,int (*compar)(const void* lhs, const void* rhs));
void removeNode(struct list_t *l,struct node_t **n,void (*deleteF)(void* data));
void printList(struct list_t *l,char *(*toStr)(const void *x));
void reverse(struct list_t *l);
void clearList(struct list_t *l,void (*deleteF)(void* data));

#endif