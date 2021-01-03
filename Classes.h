#ifndef INC_2020_10_13_HOMEWORK_CLASSES_H
#define INC_2020_10_13_HOMEWORK_CLASSES_H
enum Color {
    RED, BLACK
};

class HEAP_CLASS;

class TEST_CLASS;

class SORT_CLASS;

class HEAP_CLASS {
public:
    void heapify(int *, int, int);

    void bulid_heap(int, int *);

    int findParent(int a);

    int findSon(int, int);

};

class SORT_CLASS {

    void merge(int *, int, int, int);

public:
    void mergeSort(int *array, int left, int right);

    void InsertionSort(int *, int);

    void heapSort(int *, int);

};
class BST_TREE_CLASS {
    struct Node {
        int data;
        Node *left;
        Node *right;
    };

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

    void inorder(Node *t);

    void preorder(Node *t);

    void postorder(Node *t);

    void insert(int x);

    void remove(int x);

    void display();

    void search(int x);
};

class RED_BLACK_TREE_CLASS {
public:
    struct Node {
        int data;
        bool color;
        Node *left, *right, *parent;

        Node(int);
    };

    Node *root;
protected:
    void rotateLeft(Node *&, Node *&);

    void rotateRight(Node *&, Node *&);

    void fixViolation(Node *&, Node *&);

public:
    RED_BLACK_TREE_CLASS();

    void insert(const int &n);

};

class AVL_TREE_CLASS {
public:
    struct Node {
        int key;
        Node *left;
        Node *right;
        int height;
    };
private:

    int height(Node *);

    int max(int, int);

    Node *newNode(int);

    Node *rightRotate(Node *);

    Node *leftRotate(Node *);

    int getBalance(Node *);

public:
    Node *insert(Node *, int);

    Node *minValueNode(Node *);

    Node *deleteNode(Node *, int);

};

class TEST_CLASS {
public:
    int numberOfTests;
    int sizeOfArray;

    TEST_CLASS(int numberOfTests, int sizeOfArray);

private:
    void displayArray(int *, int);

public:
    void test(char);

};

#endif
