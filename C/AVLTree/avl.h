struct Node {
    struct Node *_left;
    struct Node *_right;
    int data;
    int height;
};


struct Node* newBSTNode(int value);
int max(int lhs,int rhs);
int getHeight(struct Node *n);
int getBalance(struct Node *n);
struct Node * rotateLeft(struct Node *x);
struct Node * rotateRight(struct Node *y);
struct Node* insert(struct Node* n,int value);
struct Node* deleteNode(struct Node *n,int value);
void inOrderVist(struct Node *n);