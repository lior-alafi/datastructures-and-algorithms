struct Node {
    struct Node *_left;
    struct Node *_right;
    void *data;
    int height;
};


struct Node* newBSTNode(void *value);
int max(int lhs,int rhs);
int getHeight(struct Node *n);
int getBalance(struct Node *n);
struct Node * rotateLeft(struct Node *x);
struct Node * rotateRight(struct Node *y);
struct Node* insert(struct Node* n,void *value,int (*compar)(const void *lhs,const void *rhs));
void deleteNodeContent(struct Node *n);
/* 
deleteValue 
1 - true, 
0 - false: meaing ownership is external)
*/
struct Node* deleteNode(struct Node *n, void *value,int (*compar)(const void *lhs,const void *rhs),int deleteValue);
void inOrderVist(struct Node *n,char *(*toString)(const void *));
void clear(struct Node **root,int deleteValue);