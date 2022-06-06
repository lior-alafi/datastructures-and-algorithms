#ifndef AVL_H
#define AVL_H
struct Node_t {
    struct Node_t *_left;
    struct Node_t *_right;
    void *data;
    int height;
};


struct Node_t* newBSTNode(void *value);
int max(int lhs,int rhs);
int getHeight(struct Node_t *n);
int getBalance(struct Node_t *n);
struct Node_t * rotateLeft(struct Node_t *x);
struct Node_t * rotateRight(struct Node_t *y);
struct Node_t* insert(struct Node_t* n,void *value,int (*compar)(const void *lhs,const void *rhs));
void deleteNodeContent(struct Node_t *n);
/* 
deleteValue 
1 - true, 
0 - false: meaing ownership is external)
*/
struct Node_t* deleteNode(struct Node_t *n, void *value,int (*compar)(const void *lhs,const void *rhs),int deleteValue);
void inOrderVist(struct Node_t *n,char *(*toString)(const void *));
void clear(struct Node_t **root,int deleteValue);
#endif