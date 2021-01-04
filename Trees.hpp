#ifndef INC_2020_10_13_HOMEWORK_TREES_HPP
#define INC_2020_10_13_HOMEWORK_TREES_HPP
enum Color {
    RED, BLACK
};

class TREE{
protected:
    struct Node {
        int data;
        Color color;
        Node *left, *right, *parent;
        int height;
        Node(int);

        Node ();

        bool isOnLeft();

        void moveDown(Node *);

        Node *uncle();

        Node *sibling();

        bool hasRedChild();
    };

    void inorder(Node *t);

    void preorder(Node *t);

    void postorder(Node *t);

};

class BST_TREE_CLASS: public TREE {

    Node *root;

    Node *makeEmpty(Node *t);

    Node *insert(int x, Node *t);

    Node *findMin(Node *t);

    Node *findMax(Node *t);

    Node *remove(int x, Node *t);

    Node *find(Node *t, int x);

public:
    BST_TREE_CLASS();

    ~BST_TREE_CLASS();

    void insert(int x);

    void remove(int x);

    Node *search(int x);

    void display(char);

};

class RED_BLACK_TREE_CLASS2 : public TREE {

    Node *root;

    void leftRotate(Node *x);

    void rightRotate(Node *x);

    void swapColors(Node *x1, Node *x2);

    void swapValues(Node *u, Node *v);

    void fixRedRed(Node *x);

    Node *successor(Node *x);

    Node *BSTreplace(Node *x);

    void deleteNode(Node *v);

    void fixDoubleBlack(Node *x);

public:

    RED_BLACK_TREE_CLASS2();

    Node *getRoot();

    Node *search(int n);

    void insert(int n);

    void remove(int n);

    void display(char);

};

class AVL_TREE_CLASS : public TREE{

private:
    Node * root;
    int height(Node *);

    int max(int, int);

    Node *newNode(int);

    Node *rightRotate(Node *);

    Node *leftRotate(Node *);

    int getBalance(Node *);

    Node *insertroot(Node *, int);

    Node *minValueNoderoot(Node *);

    Node *removeroot(Node *, int);

public:
    AVL_TREE_CLASS();

    void insert(int);

    void remove(int);

    void display(char);


};

#endif //INC_2020_10_13_HOMEWORK_TREES_HPP
