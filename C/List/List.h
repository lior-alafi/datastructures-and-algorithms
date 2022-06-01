#include <stdlib.h>


struct node {
  struct node *_next;
  void *data;
};


struct list {
 int size;
 struct node *head;
};



struct list* init();
void addToEnd(struct list *l,void* value);
void add(struct list *l,void* value);
struct node* newNode(void* value, struct node *next);
struct node **find(struct list *l,void* value,int (*compar)(const void* lhs, const void* rhs));
void removeNode(struct list *l,struct node **n);
void printList(struct list *l,char *(*toStr)(const void *x));
void reverse(struct list *l);
void clearList(struct list *l,int deleteValues);