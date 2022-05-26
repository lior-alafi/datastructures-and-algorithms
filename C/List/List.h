#include <stdlib.h>


struct node {
  struct node *_next;
  int data;
};


struct list {
 int size;
 struct node *head;
};



struct list* init();
void add(struct list *l,int value);
struct node* newNode(int value, struct node *next);
struct node **find(struct list *l,int value);
void removeNode(struct list *l,struct node **n);
void printList(struct list *l);