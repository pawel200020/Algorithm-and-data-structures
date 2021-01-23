#ifndef INC_2020_10_13_HOMEWORK_TREES_HPP
#define INC_2020_10_13_HOMEWORK_TREES_HPP
//Zadanie 4
enum Color {
    RED, BLACK
};

class TREE {
protected:
    struct Node {
        int data;
        Color color;
        Node *left, *right, *parent;
        int height;

        Node(int);

        Node();

        bool isOnLeft();

        void moveDown(Node *);

        Node *uncle();

        Node *sibling();

        bool hasRedChild();
    };

    Node *root;

    Node *makeEmpty(Node *);

    void inorder(Node *);

    void preorder(Node *);

    void postorder(Node *);

public:
    void display(char);

    Node *search(int);
};

class BST_TREE_CLASS : public TREE {

    Node *insert(int, Node *);

    Node *findMin(Node *);

    Node *remove(int, Node *);

public:
    BST_TREE_CLASS();

    ~BST_TREE_CLASS();

    void insert(int);

    void remove(int);


};

class RED_BLACK_TREE_CLASS2 : public TREE {

    void leftRotate(Node *);

    void rightRotate(Node *);

    void swapColors(Node *, Node *);

    void swapValues(Node *, Node *);

    void fixRedRed(Node *);

    Node *successor(Node *);

    Node *BSTreplace(Node *);

    void deleteNode(Node *);

    void fixDoubleBlack(Node *);

public:

    RED_BLACK_TREE_CLASS2();

    ~RED_BLACK_TREE_CLASS2();

    void insert(int);

    void remove(int);

};

class AVL_TREE_CLASS : public TREE {

private:


    int height(Node *);

    int max(int, int);

    Node *newNode(int);

    Node *rightRotate(Node *);

    Node *leftRotate(Node *);

    int getBalance(Node *);

    Node *insert(Node *, int);

    Node *minValueNode(Node *);

    Node *remove(Node *, int);

public:
    AVL_TREE_CLASS();

    ~AVL_TREE_CLASS();

    void insert(int);

    void remove(int);

};

#endif //INC_2020_10_13_HOMEWORK_TREES_HPP
