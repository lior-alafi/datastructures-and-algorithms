#include <stdio.h>
#include "cfgs.h"
#include "List/List.h"
#include "AVLTree/avl.h"

void listRoutine();
void avlRoutine();

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("%s VERSION %d.%d\n", argv[0], Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);
    }
    // listRoutine();
    avlRoutine();
    return 0;
}

void avlRoutine()
{
    struct Node *root;
    root = insert(root,5);
    root = insert(root,2);
    root = insert(root,7);
    root = insert(root,1);
    root = insert(root,6);
    root = insert(root,8);
    root = insert(root,4);
    root = insert(root,3);
    inOrderVist(root);
    printf("\n");
    // root = deleteNode(root,2);
    inOrderVist(root);
    printf("\n");
    for(int i = 0; i < 9;++i)
    {
        root = deleteNode(root,i);
    }
}

void listRoutine()
{
    struct list *l = init();
    removeNode(l, &(l->head));

    add(l, 1);
    add(l, 2);
    add(l, 3);
    add(l, 4);
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
    free(l);
}