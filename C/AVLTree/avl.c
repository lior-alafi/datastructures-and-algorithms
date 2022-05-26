#include "avl.h"
#include <stdlib.h>

struct Node *newBSTNode(int value)
{
    struct Node *n = malloc(sizeof(struct Node));

    n->data = value;
    n->height = 1;
    n->_left = n->_right = NULL;
}

int max(int lhs, int rhs)
{
    return lhs >= rhs ? lhs : rhs;
}

int getHeight(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return max(getHeight(n->_left), getHeight(n->_right)) + 1;
}
int getBalance(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }

    return getHeight(n->_left) - getHeight(n->_right);
}
struct Node *rotateLeft(struct Node *x)
{
    struct Node *T1, *T2, *T3, *y;
    y = x->_right;
    T1 = x->_left;
    T2 = y->_left;
    T3 = y->_right;

    // just for the sake of comparing the algorithm diagram
    y->_right = T3;
    y->_left = x;
    x->_right = T2;
    x->_left = T1;
    x->height = getHeight(x);
    y->height = getHeight(y);
    return y;
}

struct Node *rotateRight(struct Node *y)
{
    struct Node *T1, *T2, *T3, *x;

    x = y->_left;
    T1 = x->_left;
    T2 = x->_right;

    x->_left = T1;
    x->_right = y;
    y->_left = T2;
    x->height = getHeight(x);
    y->height = getHeight(y);

    return x;
}

struct Node *insert(struct Node *n, int value)
{
    if (n == NULL)
    {
        return newBSTNode(value);
    }

    if (n->data >= value)
    {
        n->_left = insert(n->_left, value);
    }
    else
    {
        n->_right = insert(n->_right, value);
    }

    n->height = getHeight(n);
    int violation = getHeight(n->_left) - getHeight(n->_right);

    if (violation > 1 && n->_left->data >= value)
    {
        return rotateRight(n);
    }
    else if (violation > 1 && n->_left->data < value)
    {
        n->_left = rotateLeft(n->_left);
        return rotateRight(n);
    }
    else if (violation < -1 && n->_right->data < value)
    {
        return rotateLeft(n);
    }
    else if (violation < -1 && n->_right->data >= value)
    {
        n->_right = rotateRight(n->_right);
        return rotateLeft(n);
    }

    return n;
}

struct Node *deleteNode(struct Node *x, int value)
{
    if (x == NULL)
    {
        return x;
    }

    if (x->data > value)
    {
        x->_left = deleteNode(x->_left, value);
        return x;
    }
    else if (x->data < value)
    {
        x->_right = deleteNode(x->_right, value);
        return x;
    }

    if (x->_right == NULL)
    {
        struct Node *tmp = (x == NULL)? x : x->_left;
        free(x);
        return tmp;
    }
    else if (x->_left == NULL)
    {
        struct Node *tmp = (x == NULL)? x : x->_right;
        free(x);
        return tmp;
    }

    struct Node *parentSuccessor = x,
                *successor = x->_right,
                *T1 = x->_left,
                *T2 = successor->_right,
                *T3 = parentSuccessor->_right;

    while (successor->_left != NULL)
    {
        parentSuccessor = successor;
        successor = successor->_left;
        T2 = successor->_right;
        T3 = parentSuccessor->_right;
    }
    if (parentSuccessor == x)
    {
        successor->_left = T1;
    }
    else
    {
        successor->_left = T1;
        successor->_right = parentSuccessor;
        parentSuccessor->_left = T2;
        parentSuccessor->_right = T3;
    }

    free(x);

    return successor;
}

void inOrderVist(struct Node *n)
{
    if (n == NULL)
    {
        return;
    }
    inOrderVist(n->_left);
    printf("%d ", n->data);
    inOrderVist(n->_right);
}