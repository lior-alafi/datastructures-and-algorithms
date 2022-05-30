#include <stdio.h>
#include "cfgs.h"
#include "List/List.h"
#include "AVLTree/avl.h"

void listRoutine();
void avlRoutine();
void* Int(int v);
int intCompare(const void *lhs,const void *rhs);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("%s VERSION %d.%d\n", argv[0], Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);
    }
    listRoutine();
    // avlRoutine();
    return 0;
}


void* Int(int v) {
   int *ptr = malloc(sizeof(int));
   *ptr = v;
   return ptr;
}
int intCompare(const void *lhs,const void *rhs) {
    if (*((int*)lhs) < *((int*)rhs))
    {
        return -1;
    } else if (*((int*)lhs) > *((int*)rhs))
    {
        return 1;
    }

    return 0;
}

char * int2str(const void *v)
{
    char *s = malloc(sizeof(char)*30);
    sprintf(s,"%d",*((int*)v));
    return s;
}

void avlRoutine()
{
    struct Node *root = NULL;
    root = insert(root,Int(5),intCompare);
    root = insert(root,Int(2),intCompare);
    root = insert(root,Int(7),intCompare);
    root = insert(root,Int(1),intCompare);
    root = insert(root,Int(6),intCompare);
    root = insert(root,Int(8),intCompare);
    root = insert(root,Int(4),intCompare);
    root = insert(root,Int(3),intCompare);
    inOrderVist(root,int2str);
    printf("\n");
    // root = deleteNode(root,2);
    printf("\n");
    clear(&root,1);
}

void listRoutine()
{
    struct list *l = init();
    removeNode(l, &(l->head));

    add(l, 1);
    add(l, 2);
    add(l, 3);
    add(l, 4);
    addToEnd(l,0);
    printList(l);

    reverse(l);
    printList(l);
    reverse(l);
    printList(l);
    struct node **n;

    n = find(l, 4);
    removeNode(l, n);

    n = find(l, 2);
    removeNode(l, n);
    printList(l);
    removeNode(l, n);
    n = find(l, 3);

    n = find(l, 1);
    removeNode(l, n);
    n = find(l, 0);
    removeNode(l, n);
    free(l);
}