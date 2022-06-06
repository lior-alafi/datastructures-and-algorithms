#include "avl.h"
#include <stdlib.h>

struct Node_t *newBSTNode(void *value)
{
    struct Node_t *n = malloc(sizeof(struct Node_t));

    n->data = value;
    n->height = 1;
    n->_left = n->_right = NULL;
}

int max(int lhs, int rhs)
{
    return lhs >= rhs ? lhs : rhs;
}

int getHeight(struct Node_t *n)
{
    if (n == NULL)
    {
        return 0;
    }
    n->height = max(getHeight(n->_left), getHeight(n->_right)) + 1;
    return n->height;
}


int getBalance(struct Node_t *n)
{
    if (n == NULL)
    {
        return 0;
    }

    return getHeight(n->_left) - getHeight(n->_right);
}


struct Node_t *rotateLeft(struct Node_t *x)
{
    struct Node_t *T1, *T2, *T3, *y;
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

struct Node_t *rotateRight(struct Node_t *y)
{
    struct Node_t *T1, *T2, *T3, *x;

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

struct Node_t *insert(struct Node_t *n, void *value,int (*compar)(const void *lhs,const void *rhs))
{
    if (n == NULL)
    {
        return newBSTNode(value);
    }
        
    if (compar(n->data,value) > -1) //(n->data >= value)
    {
        n->_left = insert(n->_left, value,compar);
    }
    else
    {
        n->_right = insert(n->_right, value,compar);
    }

    n->height = getHeight(n);
    int violation = getHeight(n->_left) - getHeight(n->_right);

    if (violation > 1 && compar(n->_left->data,value) > -1)// (violation > 1 && n->_left->data >= value)
    {
        return rotateRight(n);
    }
    else if (violation > 1 && compar(n->_left->data,value) == -1) //(violation > 1 && n->_left->data < value)
    {
        n->_left = rotateLeft(n->_left);
        return rotateRight(n);
    }
    else if (violation < -1 && compar(n->_right->data,value) == -1) //(violation < -1 && n->_right->data < value)
    {
        return rotateLeft(n);
    }
    else if (violation < -1 && compar(n->_right->data,value) > -1) //(violation < -1 && n->_right->data >= value)
    {
        n->_right = rotateRight(n->_right);
        return rotateLeft(n);
    }

    return n;
}
void deleteNodeContent(struct Node_t *n) {
    if(n != NULL && n->data != NULL){
        free(n->data);
        n->data = NULL;
    }
}
struct Node_t *deleteNode(struct Node_t *x, void *value,int (*compar)(const void *lhs,const void *rhs),int deleteValue)
{
    if (x == NULL)
    {
        return x;
    }

    if (compar(x->data,value) > 0  )//(x->data > value)
    {
        x->_left = deleteNode(x->_left, value,compar,deleteValue);
        return x;
    }
    else if (x->data < value)
    {
        x->_right = deleteNode(x->_right, value,compar,deleteValue);
        return x;
    }

    if (x->_right == NULL)
    {
        struct Node_t *tmp = (x == NULL)? x : x->_left;
        if (deleteValue) 
        {
            deleteNodeContent(x);
        }
        free(x);
        getHeight(tmp);
        return tmp;
    }
    else if (x->_left == NULL)
    {
        struct Node_t *tmp = (x == NULL)? x : x->_right;
        if (deleteValue) 
        {
            deleteNodeContent(x);
        }
        free(x);
        getHeight(tmp);

        return tmp;
    }

    struct Node_t *parentSuccessor = x,
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
  
  
    if (deleteValue) 
    {
            deleteNodeContent(x);
    }
    free(x);

    return successor;
}

void inOrderVist(struct Node_t *n,char *(*toString)(const void *))
{
    if (n == NULL)
    {
        return;
    }
    
    inOrderVist(n->_left,toString);
    char *buff = toString(n->data);
    printf("%s ", buff);
    free(buff);
    
    inOrderVist(n->_right,toString);
}


void clear(struct Node_t **root,int deleteValue)
{

    if(*root == NULL) 
    {
        return;
    }
    clear(&((*root)->_left),deleteValue);
    clear(&((*root)->_right),deleteValue);
    if(deleteNode) {
        deleteNodeContent(*root);
    }
    free(*root);

}