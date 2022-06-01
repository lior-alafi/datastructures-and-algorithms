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
    for (size_t i = 0; i < 5; i++)
    {
        
        add(l,Int(i));
    }
    int *p = malloc(sizeof(int));
    *p = 13;
    addToEnd(l,p);
    printList(l,int2str);

    reverse(l);
    printList(l,int2str);
    reverse(l);
    printList(l,int2str);
    struct node **n;

    // int findme = 4;
    // n = find(l, &findme,intCompare);
    // free((*n)->data);
    // removeNode(l, n);
    // printList(l,int2str);

    // findme = 2;
    //  n = find(l, &findme,intCompare);
    // free((*n)->data);
    // removeNode(l, n);
    // printList(l,int2str);
    // findme = 3;
    //  n = find(l, &findme,intCompare);
    // free((*n)->data);
    // removeNode(l, n);
    // printList(l,int2str);
    // findme = 1;
    //  n = find(l, &findme,intCompare);
    // free((*n)->data);
    // removeNode(l, n);
    // printList(l,int2str);
    // findme = 0;
    //  n = find(l, &findme,intCompare);
    // free((*n)->data);
    // removeNode(l, n);
    // printList(l,int2str);

    // findme = 13;
    // n = find(l, &findme,intCompare);
    
    // removeNode(l, n);
    // free(p);

    clearList(l,1);
    free(l);
}